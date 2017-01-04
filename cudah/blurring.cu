#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cuda.h>
#include <device_functions.h>
#include <cuda_runtime_api.h>
#include <iostream>

#include "image_processing.hpp"
#include "opencv2/core/cuda_types.hpp"

#define checkCudaErrors(val) check( (val), #val, __FILE__, __LINE__)

template<typename T>
void check(T err, const char* const func, const char* const file, const int line) {
	if (err != cudaSuccess)
	{
		std::stringstream errorStream;
		errorStream << "CUDA error at: " << file << ":" << line << "\n";
		errorStream << cudaGetErrorString(err) << " " << func << "\n";
		throw std::runtime_error(errorStream.str());
	}
}


__global__
void gaussian_blur(
	cv::cuda::PtrStepSz<uchar4> _source,
	cv::cuda::PtrStepSz<uchar4> _target,
	const float * const d_filter,
	const int filterWidth
)
{
	const int row = blockIdx.y * blockDim.y + threadIdx.y;
	const int col = blockIdx.x * blockDim.x + threadIdx.x;

	if (col >= _source.cols || row >= _source.rows)
		return;

	const int halfWidth = filterWidth / 2;

	extern __shared__ float shared_filter[];
	if (threadIdx.y < filterWidth && threadIdx.x < filterWidth)
	{
		const int filterOff = threadIdx.y*filterWidth + threadIdx.x;
		shared_filter[filterOff] = d_filter[filterOff];
	}
	__syncthreads();

	float resR = 0.0f, resG = 0.0f, resB = 0.0f;
	for (int filterRow = -halfWidth; filterRow <= halfWidth; ++filterRow)
	{
		for (int filterCol = -halfWidth; filterCol <= halfWidth; ++filterCol)
		{
			const int imageRow = min(max(row + filterRow, 0), _source.rows - 1);
			const int imageCol = min(max(col + filterCol, 0), _source.cols - 1);

			const float filterValue = shared_filter[(filterRow + halfWidth)*filterWidth + filterCol + halfWidth];
			const uchar4& imagePixel = _source( imageRow, imageCol );

			resR += imagePixel.x * filterValue;
			resG += imagePixel.y * filterValue;
			resB += imagePixel.z * filterValue;
		}
	}

	_target( row, col ) = make_uchar4(resR, resG, resB, 255);
}


void ExecuteGaussianBlur(
	cv::cuda::GpuMat& _source,
	cv::cuda::GpuMat& _target,
	float* _filter,
	int _filterSize
)
{
	cudaSetDevice(0);
	checkCudaErrors(cudaGetLastError());

	float *d_filter;
	const size_t filterSize = sizeof(float) * _filterSize * _filterSize;
	checkCudaErrors(cudaMalloc(&d_filter, filterSize));
	checkCudaErrors(cudaMemcpy(d_filter, _filter, filterSize, cudaMemcpyHostToDevice));

	cv::cuda::PtrStepSz<uchar4> source = _source;
	cv::cuda::PtrStepSz<uchar4> target = _target;

	dim3 blockSize;
	dim3 gridSize;
	int threadNum;

	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);

	threadNum = 32;
	blockSize = dim3(threadNum, threadNum, 1);
	gridSize = dim3(source.cols / threadNum + 1, source.rows / threadNum + 1, 1);

	cudaEventRecord(start);

	gaussian_blur <<<gridSize, blockSize, filterSize>>>(
			_source,
			_target,
			d_filter,
			_filterSize
		);

	cudaEventRecord(stop);
	cudaEventSynchronize(stop);
	cudaDeviceSynchronize(); checkCudaErrors(cudaGetLastError());

	checkCudaErrors(cudaFree(d_filter));
}

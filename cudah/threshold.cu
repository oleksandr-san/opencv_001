
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cuda.h>

#include <iostream>

#include <cuda.h>

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
		throw std::runtime_error( errorStream.str() );
	}
}


__global__
void convertImageSimple(
	cv::cuda::PtrStepSz<uchar4> _source,
	cv::cuda::PtrStepSz<uchar4> _target,
	unsigned char _threshold
)
{
	int y = blockDim.y*blockIdx.y + threadIdx.y;
	int x = blockDim.x*blockIdx.x + threadIdx.x;

	if (x >= _source.cols || y >= _target.rows)
		return;

	const uchar4& sourcePixel = _source(y, x);
	uchar4& targetPixel = _target(y, x);

	unsigned char pixelValue =
		( sourcePixel.x * 307 +
		  sourcePixel.y * 604 +
		  sourcePixel.z * 113 ) >> 10;

	targetPixel.w = sourcePixel.w;
	targetPixel.x = targetPixel.y = targetPixel.z =
		pixelValue > _threshold ? 255 : 0;
}

#define WARP_SIZE 32

__global__
void convertImageBlocks(
	cv::cuda::PtrStepSz<uchar4> _source,
	cv::cuda::PtrStepSz<uchar4> _target,
	int _elemsPerThread,
	unsigned char _threshold
)
{
	int y = blockDim.y * blockIdx.y + threadIdx.y;
	int x = blockDim.x * blockIdx.x + threadIdx.x;

	const int loopStart = (x / WARP_SIZE * WARP_SIZE) * (_elemsPerThread - 1) + x;
	for (int i = loopStart, j = 0; j < _elemsPerThread && i < _source.cols; i += WARP_SIZE, ++j)
	{
		const uchar4& sourcePixel = _source(y, i);
		uchar4& targetPixel = _target(y, i);

		unsigned char pixelValue =
			( sourcePixel.x * 307 +
			  sourcePixel.y * 604 +
			  sourcePixel.z * 113 ) >> 10;

		targetPixel.w = sourcePixel.w;
		targetPixel.x = targetPixel.y = targetPixel.z =
			pixelValue > _threshold ? 255 : 0;
	}
}

void ExecuteThresholdSimpleCUDA(
	cv::cuda::GpuMat& _source,
	cv::cuda::GpuMat& _target,
	unsigned char _threshold
)
{
	cudaSetDevice(0);

	dim3 blockSize;
	dim3 gridSize;
	int threadNum;
	
	cv::cuda::PtrStepSz<uchar4> source = _source;
	cv::cuda::PtrStepSz<uchar4> target = _target;

	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);

	threadNum = 512;
	blockSize = dim3(threadNum, 1, 1);
	gridSize = dim3(_source.cols / threadNum + 1, _source.rows, 1);

	cudaEventRecord(start);

	convertImageSimple<<<gridSize, blockSize>>> (source, target, _threshold);

	cudaEventRecord(stop);
	cudaEventSynchronize(stop);
	cudaDeviceSynchronize(); 
	checkCudaErrors(cudaGetLastError());
}

void ExecuteThresholdBlocksCUDA(
	cv::cuda::GpuMat& _source,
	cv::cuda::GpuMat& _target,
	unsigned char _threshold
)
{
	cudaSetDevice(0);

	dim3 blockSize;
	dim3 gridSize;
	
	cv::cuda::PtrStepSz<uchar4> source = _source;
	cv::cuda::PtrStepSz<uchar4> target = _target;

	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);

	const int elemsPerThread = 16;
	const int threadNum = 256 ;
	blockSize = dim3(threadNum, 1, 1);
	gridSize = dim3(_source.cols / ( elemsPerThread * threadNum ) + 1, _source.rows, 1);

	cudaEventRecord(start);

	convertImageBlocks<<<gridSize, blockSize>>> (source, target, elemsPerThread, _threshold);

	cudaEventRecord(stop);
	cudaEventSynchronize(stop);
	cudaDeviceSynchronize(); 
	checkCudaErrors(cudaGetLastError());
}

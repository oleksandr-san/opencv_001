
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
void grayscale_simple(
	cv::cuda::PtrStepSz<uchar4> _source,
	cv::cuda::PtrStepSz<uchar4> _target
)
{
	int y = blockDim.y*blockIdx.y + threadIdx.y;
	int x = blockDim.x*blockIdx.x + threadIdx.x;

	if (x >= _source.cols || y >= _target.rows)
		return;

	const uchar4& sourcePixel = _source(y, x);
	uchar4& targetPixel = _target(y, x);

	targetPixel.w = sourcePixel.w;
	targetPixel.x = targetPixel.y = targetPixel.z =
		( sourcePixel.x * 307 +
		  sourcePixel.y * 604 +
		  sourcePixel.z * 113 ) >> 10;
}

void ExecuteGrayscaleCUDASimple(
	cv::cuda::GpuMat& _source,
	cv::cuda::GpuMat& _target
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

	grayscale_simple <<<gridSize, blockSize>>> (source, target);

	cudaEventRecord(stop);
	cudaEventSynchronize(stop);
	cudaDeviceSynchronize(); 
	checkCudaErrors(cudaGetLastError());
}

void ExecuteGrayscaleCUDAOptimized(
	cv::cuda::GpuMat& _source,
	cv::cuda::GpuMat& _target
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

	grayscale_optimized <<<gridSize, blockSize>>> (source, target, elemsPerThread);

	cudaEventRecord(stop);
	cudaEventSynchronize(stop);
	cudaDeviceSynchronize(); 
	checkCudaErrors(cudaGetLastError());

}
#ifndef __IMAGE_PROCESSING_HPP__
#define __IMAGE_PROCESSING_HPP__

#include "opencv2/core/cuda.hpp"

void ExecuteGrayscaleCUDASimple(
	cv::cuda::GpuMat& _source,
	cv::cuda::GpuMat& _target
);

void ExecuteGrayscaleCUDAOptimized(
	cv::cuda::GpuMat& _source,
	cv::cuda::GpuMat& _target
);

void ExecuteThresholdSimpleCUDA(
	cv::cuda::GpuMat& _source,
	cv::cuda::GpuMat& _target,
	unsigned char _threshold
);

void ExecuteThresholdBlocksCUDA(
	cv::cuda::GpuMat& _source,
	cv::cuda::GpuMat& _target,
	unsigned char _threshold
);

void ExecuteGaussianBlur(
	cv::cuda::GpuMat& _source,
	cv::cuda::GpuMat& _target,
	float* _filter,
	int _filterSize
);

#endif
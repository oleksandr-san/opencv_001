
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/cudafilters.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudaarithm.hpp>

#include "sources/tasks/task_implementations/opencv_cuda/opencv_cuda_image_processing_task.hpp"
#include "sources/tasks/task_implementations/base/task_utils.hpp"

namespace Tasks {

	void OpenCV_CUDA_GrayscaleTask::processObject(
		cv::Mat& _hostSource,
		cv::cuda::GpuMat& _deviceSource,
		cv::cuda::GpuMat& _deviceTarget
	)
	{
		cv::cuda::cvtColor( _deviceSource, _deviceTarget, cv::COLOR_BGRA2GRAY );
	}

	void OpenCV_CUDA_BinarizationTask::processObject(
		cv::Mat& _hostSource,
		cv::cuda::GpuMat& _deviceSource,
		cv::cuda::GpuMat& _deviceTarget
	)
	{
		cv::cuda::cvtColor( _deviceSource, _deviceSource, cv::COLOR_BGRA2GRAY );
		cv::cuda::threshold(_deviceSource, _deviceTarget, 128, 255, CV_THRESH_BINARY);
	}

	cv::Ptr<cv::cuda::Filter>
	OpenCV_CUDA_BlurTask::createFilter(cv::Mat & _matrix)
	{
		const int kernelSize = getProperties().getBlurringKernelSize();
		const double sigmaX = getProperties().getSigmaX();

		return cv::cuda::createGaussianFilter(
				_matrix.type(),
				-1,
				cv::Size( kernelSize, kernelSize ),
				sigmaX
			);
	}

}
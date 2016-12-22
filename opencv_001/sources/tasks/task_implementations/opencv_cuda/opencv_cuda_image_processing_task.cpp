
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/cudafilters.hpp>
#include <opencv2/cudaimgproc.hpp>

#include "sources/tasks/task_implementations/opencv_cuda/opencv_cuda_image_processing_task.hpp"

namespace Tasks {

		void OpenCV_CUDA_GrayscaleTask::processObject(
			cv::Mat& _hostSource,
			cv::cuda::GpuMat& _deviceSource,
			cv::cuda::GpuMat& _deviceTarget
		)
		{
			cv::cuda::cvtColor( _deviceSource, _deviceTarget, cv::COLOR_RGB2GRAY );
		}

}
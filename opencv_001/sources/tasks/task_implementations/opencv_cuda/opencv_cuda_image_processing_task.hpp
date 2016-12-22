#ifndef __OPENCV_CUDA_IMAGE_PROCESSING_TASK_HPP__
#define __OPENCV_CUDA_IMAGE_PROCESSING_TASK_HPP__

#include <opencv2/core.hpp>

#include "sources/tasks/task_implementations/opencv_cuda/base_opencv_cuda_task.hpp"

namespace Tasks {

	class OpenCV_CUDA_GrayscaleTask
		:	public Base_OpenCV_CUDA_Task< TaskType::Grayscale >
	{

		typedef
			Base_OpenCV_CUDA_Task< TaskType::Grayscale >
			BaseClass;

	public:

		OpenCV_CUDA_GrayscaleTask( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual void processObject(
			cv::Mat& _hostSource,
			cv::cuda::GpuMat& _deviceSource,
			cv::cuda::GpuMat& _deviceTarget
			) override;

	};

}

#endif
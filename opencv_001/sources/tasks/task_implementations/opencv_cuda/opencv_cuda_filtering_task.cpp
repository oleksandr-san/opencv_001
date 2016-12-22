#include "sources/tasks/task_implementations/opencv_cuda/opencv_cuda_filtering_task.hpp"

namespace Tasks {

	cv::Ptr<cv::cuda::Filter>
	OpenCV_CUDA_BoxFilter_Task::createFilter(cv::Mat & _matrix)
	{
		return cv::cuda::createBoxFilter(
				_matrix.type(), -1, cv::Size( 13, 13 )
			);
	}

	cv::Ptr<cv::cuda::Filter>
	OpenCV_CUDA_SobelFilter_Task::createFilter(cv::Mat & _matrix)
	{
		return cv::cuda::createSobelFilter(
				_matrix.type(), -1, 1, 1
			);
	}

}
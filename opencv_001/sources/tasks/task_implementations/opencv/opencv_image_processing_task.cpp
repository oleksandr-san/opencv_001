#include "sources/tasks/task_implementations/opencv/opencv_image_processing_task.hpp"

namespace Tasks {

	void
	OpenCV_Grayscale_Task::runInternal( ObjectData& _data )
	{
		cv::cvtColor( _data.m_source, _data.m_target, cv::COLOR_BGRA2GRAY );
	}

	void
	OpenCV_Blur_Task::runInternal( ObjectData& _data ) 
	{
		const int kernelSize = getProperties().getBlurringKernelSize();

		cv::GaussianBlur(
			_data.m_source,
			_data.m_target,
			cv::Size( kernelSize, kernelSize ),
			getProperties().getSigmaX()
		);
	}

}
#include "sources/tasks/task_implementations/opencv/opencv_image_processing_task.hpp"

namespace Tasks {

	void
	OpenCV_GrayscaleTask::runInternal( ObjectData& _data )
	{
		cv::cvtColor( _data.m_source, _data.m_target, cv::COLOR_BGRA2GRAY );
	}

	void
	OpenCV_BlurTask::runInternal( ObjectData& _data ) 
	{
		const int kernelSize = getProperties().getBlurringKernelSize();
		const double sigmaX = getProperties().getSigmaX();

		cv::GaussianBlur(
			_data.m_source,
			_data.m_target,
			cv::Size( kernelSize, kernelSize ),
			sigmaX
		);
	}

	void
	OpenCV_BinarizationTask::runInternal( ObjectData& _data )
	{
		cv::cvtColor( _data.m_source, _data.m_source, cv::COLOR_BGRA2GRAY );
		cv::threshold(_data.m_source, _data.m_target, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	}

}
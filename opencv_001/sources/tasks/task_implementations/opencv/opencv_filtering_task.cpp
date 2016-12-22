#include "sources/tasks/task_implementations/opencv/opencv_filtering_task.hpp"

#include <opencv2/imgproc/imgproc.hpp>

namespace Tasks {

	void
	OpenCV_BoxFilter_Task::processObject(
		cv::Mat & _source,
		cv::Mat & _target
	)
	{
		auto kernelSizeProperty
			= getProperties().getIntProperty( TaskProperty::KernelSize );

		const int kernelSizeValue
			= kernelSizeProperty ? *kernelSizeProperty : 16;

		cv::boxFilter(
			_source,
			_target,
			-1,
			cv::Size( kernelSizeValue, kernelSizeValue )
		);
	}

	void
	OpenCV_SobelFilter_Task::processObject(
		cv::Mat & _source,
		cv::Mat & _target
	)
	{
		cv::Sobel(_source, _target, -1, 3, 3, 5 );
	}

}
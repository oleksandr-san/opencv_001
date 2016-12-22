#include "sources/tasks/task_implementations/opencv/opencv_image_processing_task.hpp"

namespace Tasks {

	void
	OpenCV_Grayscale_Task::processObject(
		cv::Mat & _source,
		cv::Mat & _target
	)
	{
		cv::cvtColor( _source, _target, cv::COLOR_RGB2GRAY );
	}

}
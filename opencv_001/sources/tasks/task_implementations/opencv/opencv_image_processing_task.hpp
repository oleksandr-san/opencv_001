#ifndef __OPENCV_IMAGE_PROCESSING_TASK_HPP__
#define __OPENCV_IMAGE_PROCESSING_TASK_HPP__

#include <unordered_map>
#include <opencv2/cudafilters.hpp>

#include "sources/tasks/task_implementations/opencv/base_opencv_task.hpp"

namespace Tasks {

	class OpenCV_Grayscale_Task
		:	public Base_OpenCV_Task< TaskType::Grayscale >
	{

		typedef
			Base_OpenCV_Task< TaskType::Grayscale >
			BaseClass;

	public:

		OpenCV_Grayscale_Task( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual void processObject(
				cv::Mat& _source,
				cv::Mat& _target
			) override;

	};

}

#endif#pragma once

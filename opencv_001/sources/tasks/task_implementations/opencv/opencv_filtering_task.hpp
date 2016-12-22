#ifndef __OPENCV_FILTERING_TASK_HPP__
#define __OPENCV_FILTERING_TASK_HPP__

#include <unordered_map>
#include <opencv2/cudafilters.hpp>

#include "sources/tasks/task_implementations/opencv/base_opencv_task.hpp"

namespace Tasks {

	class OpenCV_BoxFilter_Task
		:	public Base_OpenCV_Task< TaskType::BoxFilter >
	{

		typedef
			Base_OpenCV_Task< TaskType::BoxFilter >
			BaseClass;

	public:

		OpenCV_BoxFilter_Task( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual void processObject(
				cv::Mat& _source,
				cv::Mat& _target
			) override;

	};

	class OpenCV_SobelFilter_Task
		:	public Base_OpenCV_Task< TaskType::SobelFilter >
	{

		typedef
			Base_OpenCV_Task< TaskType::SobelFilter >
			BaseClass;

	public:

		OpenCV_SobelFilter_Task( ITaskProperties::Ptr _properties )
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

#endif
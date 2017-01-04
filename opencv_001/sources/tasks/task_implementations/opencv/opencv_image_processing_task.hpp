#ifndef __OPENCV_IMAGE_PROCESSING_TASK_HPP__
#define __OPENCV_IMAGE_PROCESSING_TASK_HPP__

#include <unordered_map>
#include <opencv2/cudafilters.hpp>

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

namespace Tasks {

	class OpenCV_Grayscale_Task
		:	public BaseTypedTask<
							TaskType::Grayscale
						,	TaskImplementationType::OpenCV
					>
	{

		typedef
			BaseTypedTask<
						TaskType::Grayscale
					,	TaskImplementationType::OpenCV
				>
			BaseClass;

	public:

		OpenCV_Grayscale_Task( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual void runInternal( ObjectData& _data )  override;

	};


	class OpenCV_Blur_Task
		:	public BaseTypedTask<
							TaskType::Blur
						,	TaskImplementationType::OpenCV
					>
	{

		typedef
			BaseTypedTask<
						TaskType::Blur
					,	TaskImplementationType::OpenCV
				>
			BaseClass;

	public:

		OpenCV_Blur_Task( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual void runInternal( ObjectData& _data )  override;

	};

}

#endif#pragma once

#ifndef __BASE_OPENCV_TASK_HPP__
#define __BASE_OPENCV_TASK_HPP__

#include <opencv2/imgproc/imgproc.hpp>

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

namespace Tasks {

	template < TaskType::Enum _Type >
	class Base_OpenCV_Task
		:	public BaseTypedTask<
					_Type,
					TaskImplementationType::OpenCV
				>
	{

		typedef
			BaseTypedTask<
				_Type,
				TaskImplementationType::OpenCV
			>
			BaseClass;

	public:

		Base_OpenCV_Task( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual void runInternal( TaskContext& _context ) override
		{
			cv::Mat source;
			loadObject( source, _context );

			cv::Mat target;
			processObject( source, target );

			saveObject( target, _context );
		}

		virtual void processObject(
				cv::Mat& _source,
				cv::Mat& _target
			) = 0;

	};

}

#endif

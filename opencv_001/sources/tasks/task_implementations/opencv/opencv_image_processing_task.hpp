#ifndef __OPENCV_IMAGE_PROCESSING_TASK_HPP__
#define __OPENCV_IMAGE_PROCESSING_TASK_HPP__

#include <unordered_map>
#include <opencv2/cudafilters.hpp>

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

#define DEFINE_OPENCV_TASK( _type )									\
	class OpenCV_##_type##Task										\
		:	public BaseTypedTask<									\
							TaskType::_type							\
						,	TaskImplementationType::OpenCV			\
					>												\
	{																\
																	\
		typedef														\
			BaseTypedTask<											\
						TaskType::_type								\
					,	TaskImplementationType::OpenCV				\
				>													\
			BaseClass;												\
																	\
	public:															\
																	\
		OpenCV_##_type##Task( ITaskProperties::Ptr _properties )	\
			:	BaseClass( _properties )							\
		{															\
		}															\
																	\
	protected:														\
																	\
		virtual void runInternal( ObjectData& _data )  override;	\
																	\
	};

namespace Tasks {

	DEFINE_OPENCV_TASK( Grayscale )
	
	DEFINE_OPENCV_TASK( Binarization )
	
	DEFINE_OPENCV_TASK( Blur )

}

#endif

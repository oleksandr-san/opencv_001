#ifndef __CUSTOM_IMAGE_PROCESSING_TASK_HPP__
#define __CUSTOM_IMAGE_PROCESSING_TASK_HPP__

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

namespace Tasks {

	class CustomGrayscaleTask
		:	public BaseTypedTask<
					TaskType::Grayscale,
					TaskImplementationType::Custom
				>
	{

		typedef
			BaseTypedTask<
				TaskType::Grayscale,
				TaskImplementationType::Custom
			>
			BaseClass;

	public:

		CustomGrayscaleTask( ITaskProperties::Ptr _properties );

	protected:

		virtual void runInternal( ObjectData& _data ) override;
	};

	class CustomBlurTask
		:	public BaseTypedTask<
					TaskType::Blur,
					TaskImplementationType::Custom
				>
	{

		typedef
			BaseTypedTask<
				TaskType::Blur,
				TaskImplementationType::Custom
			>
			BaseClass;

	public:

		CustomBlurTask( ITaskProperties::Ptr _properties );

	protected:

		virtual void runInternal( ObjectData& _data ) override;

		virtual void prepareObjectData( ObjectData& _data, TaskContext& _context ) override;

	};

}

#endif
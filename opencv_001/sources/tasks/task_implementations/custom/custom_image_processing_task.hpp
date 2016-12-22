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

		virtual void runInternal( TaskContext& _context ) override;
	};
}

#endif
#ifndef __CUSTOM_SOBEL_FILTER_TASK_HPP__
#define __CUSTOM_SOBEL_FILTER_TASK_HPP__

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

namespace Tasks {

	class CustomSobelFilterTask
		:	public BaseTypedTask<
					TaskType::SobelFilter,
					TaskImplementationType::Custom
				>
	{

		typedef
			BaseTypedTask<
				TaskType::SobelFilter,
				TaskImplementationType::Custom
			>
			BaseClass;

	public:

		CustomSobelFilterTask( ITaskProperties::Ptr _properties );

	protected:

		virtual void runInternal( TaskContext& _context ) override;
	};
}

#endif
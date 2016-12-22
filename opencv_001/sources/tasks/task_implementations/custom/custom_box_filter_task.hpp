#ifndef __CUSTOM_BOX_FILTER_TASK_HPP__
#define __CUSTOM_BOX_FILTER_TASK_HPP__

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

namespace Tasks {

	class CustomBoxFilterTask
		:	public BaseTypedTask<
					TaskType::BoxFilter,
					TaskImplementationType::Custom
				>
	{

		typedef
			BaseTypedTask<
				TaskType::BoxFilter,
				TaskImplementationType::Custom
			>
			BaseClass;

	public:

		CustomBoxFilterTask( ITaskProperties::Ptr _properties );

	protected:

		virtual void runInternal( TaskContext& _context ) override;
	};
}

#endif
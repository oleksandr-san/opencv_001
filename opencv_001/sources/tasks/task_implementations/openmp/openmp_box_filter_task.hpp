#ifndef __OPENMP_BOX_FILTER_TASK_HPP__
#define __OPENMP_BOX_FILTER_TASK_HPP__

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

namespace Tasks {

	class OpenMPBoxFilterTask
		:	public BaseTypedTask<
					TaskType::BoxFilter,
					TaskImplementationType::OpenMP
				>
	{

		typedef
			BaseTypedTask<
				TaskType::BoxFilter,
				TaskImplementationType::OpenMP
			>
			BaseClass;

	public:

		OpenMPBoxFilterTask( ITaskProperties::Ptr _properties );

	protected:

		virtual void runInternal( TaskContext& _context ) override;
	};
}

#endif
#ifndef __OPENMP_SOBEL_FILTER_TASK_HPP__
#define __OPENMP_SOBEL_FILTER_TASK_HPP__

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

namespace Tasks {

	class OpenMPSobelFilterTask
		:	public BaseTypedTask<
					TaskType::SobelFilter,
					TaskImplementationType::OpenMP
				>
	{

		typedef
			BaseTypedTask<
				TaskType::SobelFilter,
				TaskImplementationType::OpenMP
			>
			BaseClass;

	public:

		OpenMPSobelFilterTask( ITaskProperties::Ptr _properties );

	protected:

		virtual void runInternal( TaskContext& _context ) override;
	};
}

#endif
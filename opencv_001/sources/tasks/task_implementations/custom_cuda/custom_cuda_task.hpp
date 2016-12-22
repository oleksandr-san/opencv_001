#ifndef __CUSTOM_CUDA_TASK_HPP__
#define __CUSTOM_CUDA_TASK_HPP__

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

namespace Tasks {

	template < TaskType::Enum _Type >
	class CustomCUDATask
		:	public BaseTypedTask<
				_Type,
				TaskImplementationType::Custom
			>
	{
		typedef
			BaseTypedTask<
				_Type,
				TaskImplementationType::Custom
			>
			BaseClass;

	public:

		CustomCUDATask( ITaskProperties::Ptr _properties );

	protected:

		virtual void runInternal( TaskContext& _context ) override;
	};

	typedef CustomCUDATask< TaskType::Grayscale > GrayscaleCUDA;
	typedef CustomCUDATask< TaskType::BoxFilter > BoxFilterCUDA;
	typedef CustomCUDATask< TaskType::SobelFilter > SobelFilterCUDA;

}

#endif
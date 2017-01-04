#ifndef __CUSTOM_CUDA_TASK_HPP__
#define __CUSTOM_CUDA_TASK_HPP__

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

namespace Tasks {

	template < TaskType::Enum _Type >
	class CustomCUDATask
		:	public BaseTypedTask<
				_Type,
				TaskImplementationType::Custom_CUDA
			>
	{
		typedef
			BaseTypedTask<
				_Type,
				TaskImplementationType::Custom_CUDA
			>
			BaseClass;

	public:

		CustomCUDATask( ITaskProperties::Ptr _properties );

	protected:

		virtual void runInternal( ObjectData& _data ) override;

		virtual void prepareObjectData( ObjectData& _data, TaskContext& _context ) override;

		virtual void saveObjectData( ObjectData& _data, TaskContext& _context ) override;

	};

	typedef CustomCUDATask< TaskType::Grayscale > GrayscaleCUDA;
	typedef CustomCUDATask< TaskType::Blur > BlurCUDA;

}

#endif
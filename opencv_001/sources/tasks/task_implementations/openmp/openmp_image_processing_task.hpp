#ifndef __OPENMP_IMAGE_PROCESSING_TASK_HPP__
#define __OPENMP_IMAGE_PROCESSING_TASK_HPP__

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

namespace Tasks {

	class OpenMPGrayscaleTask
		:	public BaseTypedTask<
					TaskType::Grayscale,
					TaskImplementationType::OpenMP
				>
	{

		typedef
			BaseTypedTask<
				TaskType::Grayscale,
				TaskImplementationType::OpenMP
			>
			BaseClass;

	public:

		OpenMPGrayscaleTask( ITaskProperties::Ptr _properties );

	protected:

		virtual void runInternal( ObjectData& _data ) override;
	};


	class OpenMPBlurTask
		:	public BaseTypedTask<
					TaskType::Blur,
					TaskImplementationType::OpenMP
				>
	{

		typedef
			BaseTypedTask<
				TaskType::Blur,
				TaskImplementationType::OpenMP
			>
			BaseClass;

	public:

		OpenMPBlurTask( ITaskProperties::Ptr _properties );

	protected:

		virtual void runInternal( ObjectData& _data ) override;

		virtual void prepareObjectData( ObjectData& _data, TaskContext& _context ) override;

	};

}

#endif
#include "sources/tasks/task_implementations/custom_cuda/custom_cuda_task.hpp"

namespace Tasks {
	
	template < TaskType::Enum _Type >
	CustomCUDATask< _Type >::CustomCUDATask( 
			ITaskProperties::Ptr _properties
	)
		:	BaseClass( _properties )
	{
	}

	template < TaskType::Enum _Type >
	void
	CustomCUDATask< _Type >::runInternal( TaskContext& _context )
	{
		cv::Mat image;
		loadObject( image, _context );

		saveObject( image, _context );
	}

	template class CustomCUDATask< TaskType::Grayscale >;
	template class CustomCUDATask< TaskType::BoxFilter >;
	template class CustomCUDATask< TaskType::SobelFilter >;
}
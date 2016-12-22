#include "sources/tasks/task_implementations/openmp/openmp_sobel_filter_task.hpp"

namespace Tasks {
	
	OpenMPSobelFilterTask::OpenMPSobelFilterTask( 
			ITaskProperties::Ptr _properties
		)
		:	BaseClass( _properties )
	{
	}

	void OpenMPSobelFilterTask::runInternal( TaskContext& _context )
	{
		cv::Mat image;
		loadObject( image, _context );

		saveObject( image, _context );
	}
}
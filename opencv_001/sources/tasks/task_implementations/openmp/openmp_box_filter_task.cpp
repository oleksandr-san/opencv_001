#include "sources/tasks/task_implementations/openmp/openmp_box_filter_task.hpp"

namespace Tasks {
	
	OpenMPBoxFilterTask::OpenMPBoxFilterTask( 
			ITaskProperties::Ptr _properties
		)
		:	BaseClass( _properties )
	{
	}

	void OpenMPBoxFilterTask::runInternal( TaskContext& _context )
	{
		cv::Mat image;
		loadObject( image, _context );



		saveObject( image, _context );
	}
}
#include "sources/tasks/task_implementations/custom/custom_sobel_filter_task.hpp"

namespace Tasks {
	
	CustomSobelFilterTask::CustomSobelFilterTask( 
			ITaskProperties::Ptr _properties
		)
		:	BaseClass( _properties )
	{
	}

	void CustomSobelFilterTask::runInternal( TaskContext& _context )
	{
		cv::Mat image;
		loadObject( image, _context );

		saveObject( image, _context );
	}
}
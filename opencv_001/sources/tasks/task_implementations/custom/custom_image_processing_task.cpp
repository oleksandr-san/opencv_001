#include "sources/tasks/task_implementations/custom/custom_image_processing_task.hpp"

#include <opencv2/highgui/highgui.hpp>

namespace Tasks {
	
	CustomGrayscaleTask::CustomGrayscaleTask( 
			ITaskProperties::Ptr _properties
		)
		:	BaseClass( _properties )
	{
	}

	void CustomGrayscaleTask::runInternal( TaskContext& _context )
	{
		cv::Mat image;
		loadObject( image, _context );

		for ( int i = 0; i < image.rows; ++i )
		{
			for ( int j = 0; j < image.cols; ++j )
			{
				cv::Vec3b& pixel = image.at< cv::Vec3b >( i, j );

				uchar newValue =
						( pixel.val[0] * 307 +
						  pixel.val[1] * 604 +
						  pixel.val[2] * 113 ) >> 10;

				pixel.val[0] = pixel.val[1] = pixel.val[2] = newValue;
			}
		}

		saveObject( image, _context );
	}
}
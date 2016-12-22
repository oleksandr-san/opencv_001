#include "sources/tasks/task_implementations/openmp/openmp_image_processing_task.hpp"

#include <opencv2/highgui/highgui.hpp>

namespace Tasks {
	
	OpenMPGrayscaleTask::OpenMPGrayscaleTask( 
			ITaskProperties::Ptr _properties
		)
		:	BaseClass( _properties )
	{
	}

	void OpenMPGrayscaleTask::runInternal( TaskContext& _context )
	{
		cv::Mat image;
		loadObject( image, _context );

		#pragma omp parallel for shared( image ) schedule( runtime )
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
#include "sources/tasks/task_implementations/openmp/openmp_image_processing_task.hpp"
#include "sources/tasks/task_implementations/base/task_utils.hpp"

#include <opencv2/highgui/highgui.hpp>

namespace Tasks {

	OpenMPGrayscaleTask::OpenMPGrayscaleTask(
		ITaskProperties::Ptr _properties
	)
		: BaseClass(_properties)
	{
	}

	void OpenMPGrayscaleTask::runInternal(ObjectData& _data)
	{
		//	♂
		#pragma omp parallel for shared( _data )
		for (int i = 0; i < _data.m_source.rows; ++i)
		{
			for (int j = 0; j < _data.m_source.cols; ++j)
			{
				auto& sourcePixel = _data.m_source.at< cv::Vec4b >( i, j );
				auto& targetPixel = _data.m_target.at< cv::Vec4b >( i, j );

				targetPixel[ 3 ] = sourcePixel[ 3 ];
				targetPixel.val[0] = targetPixel.val[1] = targetPixel.val[2] =
					( sourcePixel.val[0] * 307 +
					  sourcePixel.val[1] * 604 +
					  sourcePixel.val[2] * 113 ) >> 10;
			}
		}
	}


	OpenMPBinarizationTask::OpenMPBinarizationTask( 
			ITaskProperties::Ptr _properties
	)
		:	BaseClass( _properties )
	{
	}

	void OpenMPBinarizationTask::runInternal( ObjectData& _data )
	{
		float threshold = Utils::calculateThresholdValue( _data );

		#pragma omp parallel for shared( _data )
		for ( int i = 0; i < _data.m_source.rows; ++i )
		{
			for ( int j = 0; j < _data.m_source.cols; ++j )
			{
				auto& sourcePixel = _data.m_source.at< cv::Vec4b >( i, j );
				auto& targetPixel = _data.m_target.at< cv::Vec4b >( i, j );

				unsigned char pixelValue =
					( sourcePixel.val[0] * 307 +
					  sourcePixel.val[1] * 604 +
					  sourcePixel.val[2] * 113 ) >> 10;

				targetPixel.val[3] = sourcePixel.val[3];
				targetPixel.val[0] = targetPixel.val[1] = targetPixel.val[2]
					= pixelValue > threshold ? 255 : 0;
			}
		}

		//const int pixelsCount = _data.m_source.rows * _data.m_source.cols;

		//#pragma omp parallel for shared( _data )
		//for ( int i = 0; i < pixelsCount; ++i )
		//{
		//	auto& sourcePixel = _data.m_source.at< cv::Vec4b >( i );
		//	auto& targetPixel = _data.m_target.at< cv::Vec4b >( i );

		//	unsigned char pixelValue =
		//		( sourcePixel.val[0] * 307 +
		//		  sourcePixel.val[1] * 604 +
		//		  sourcePixel.val[2] * 113 ) >> 10;

		//	targetPixel.val[3] = sourcePixel.val[3];
		//	targetPixel.val[0] = targetPixel.val[1] = targetPixel.val[2]
		//		= pixelValue > threshold ? 255 : 0;
		//}
	}


	OpenMPBlurTask::OpenMPBlurTask(
		ITaskProperties::Ptr _properties
	)
		: BaseClass(_properties)
	{
	}

	void OpenMPBlurTask::runInternal(ObjectData& _data)
	{
		const int filterWidth = getProperties().getBlurringKernelSize();

		auto& source = _data.m_source;
		auto& target = _data.m_target;

		const int colsCount = source.cols;
		const int rowsCount = source.rows;

		float* filterPtr = _data.m_filter.get();
		const int halfWidth = filterWidth / 2;

		typedef cv::Vec4b PixelType;

		cv::Vec4f res;

		#pragma omp parallel for private( res ) shared( source )
		for (int row = 0; row < rowsCount; ++row)
		{
			for (int col = 0; col < colsCount; ++col)
			{
				res[ 0 ] = res[ 1 ] = res[ 2 ] = 0.f;

				for (int filterRow = -halfWidth; filterRow <= halfWidth; ++filterRow)
				{
					for (int filterCol = -halfWidth; filterCol <= halfWidth; ++filterCol)
					{
						const int imageRow = std::min(std::max(row + filterRow, 0), rowsCount - 1);
						const int imageCol = std::min(std::max(col + filterCol, 0), colsCount - 1);

						auto& imagePixel = source.at< PixelType >( imageRow * colsCount + imageCol );
						for ( int px = 0; px < PixelType::channels; ++px )
							res[ px ] += imagePixel[ px ] * filterPtr[(filterRow + halfWidth)*filterWidth + filterCol + halfWidth ];
					}
				}

				auto& blurredImagePixel = _data.m_target.at< PixelType >( row * target.cols + col );
				for ( int px = 0; px < PixelType::channels; ++px )
					blurredImagePixel[ px ] = static_cast< PixelType::value_type >( res[ px ] );
			}
		}
	}

	void OpenMPBlurTask::prepareObjectData(ObjectData & _data, TaskContext & _context)
	{
		BaseClass::prepareObjectData( _data, _context );

		const int filterWidth = getProperties().getBlurringKernelSize();
		const float filterSigma = static_cast<float>(getProperties().getSigmaX());

		_data.m_filter.reset( new float[filterWidth * filterWidth] );
		float* filterPtr = _data.m_filter.get();

		float filterSum = 0.f;
		const int halfWidth = filterWidth / 2;

		//#pragma omp parallel for shared( filterPtr )
		for (int r = -halfWidth; r <= halfWidth; ++r)
			for (int c = -halfWidth; c <= halfWidth; ++c)
			{
				float filterValue = expf(-(float)(c * c + r * r) / (2.f * filterSigma * filterSigma));
				filterPtr[(r + halfWidth) * filterWidth + c + halfWidth] = filterValue;
				filterSum += filterValue;
			}

		float normalizationFactor = 1.f / filterSum;

		//#pragma omp parallel for shared( filterPtr )
		for (int r = -halfWidth; r <= halfWidth; ++r)
			for (int c = -halfWidth; c <= halfWidth; ++c)
				filterPtr[(r + halfWidth) * filterWidth + c + halfWidth] *= normalizationFactor;
	}

}
#include "sources/tasks/task_implementations/custom/custom_image_processing_task.hpp"
#include "sources/tasks/task_implementations/base/task_utils.hpp"

#include <opencv2/highgui/highgui.hpp>

namespace Tasks {
	
	CustomGrayscaleTask::CustomGrayscaleTask( 
			ITaskProperties::Ptr _properties
		)
		:	BaseClass( _properties )
	{
	}

	void CustomGrayscaleTask::runInternal( ObjectData& _data )
	{
		_data.m_source.copyTo( _data.m_target );

		for ( int i = 0; i < _data.m_source.rows; ++i )
		{
			for ( int j = 0; j < _data.m_source.cols; ++j )
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


	CustomBlurTask::CustomBlurTask( 
			ITaskProperties::Ptr _properties
	)
		:	BaseClass( _properties )
	{
	}

	void CustomBlurTask::runInternal(ObjectData& _data)
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

	void CustomBlurTask::prepareObjectData(ObjectData & _data, TaskContext & _context)
	{
		BaseClass::prepareObjectData( _data, _context );

		Utils::FilterCreator::createBlurFilter(
			_data,
			getProperties().getBlurringKernelSize(),
			getProperties().getSigmaX()
		);
	}

	//void
	//CustomBlurTask::runInternal( ObjectData& _data )
	//{
	//	const int n = getProperties().getBlurringKernelSize();
	//	const double sigma = getProperties().getSigmaX();

	//	auto wIdeal = std::sqrt(( 12 * sigma * sigma / n ) +1 );

	//	auto wl = static_cast< int >( std::floor(wIdeal) );
	//	if( wl % 2 == 0 ) wl--;
	//	auto wu = wl + 2;
	//			
	//	auto mIdeal = (12*sigma*sigma - n*wl*wl - 4*n*wl - 3*n)/(-4*wl - 4);
	//	auto m = std::round(mIdeal);

	//	for( int i = 0; i < n; i++ )
	//		boxBlur< cv::Vec3b >( _data, ( ( i < m ? wl : wu ) - 1 ) / 2 );
	//}

	template < typename _DataType >
	void
	boxBlur( ObjectData& _data, int _r )
	{
		_DataType val = 0;

		const int rValue = ( _r + _r + 1 ) * ( _r + _r + 1 );
		for(int i = 0; i < _data.m_source.rows; i++)
			for(int j = 0; j < _data.m_source.cols; j++)
			{
				val = 0;

				for(int iy = i - _r; iy < i + _r + 1; iy++)
					for(int ix = j - _r; ix < j + _r + 1; ix++)
					{
						int x = std::min( _data.m_source.cols - 1, std::max(0, ix) );
						int y = std::min( _data.m_source.rows - 1, std::max(0, iy) );

						_DataType& pixel = _data.m_source.at< _DataType >( y * _data.m_source.cols + x );

						for ( int px = 0; px < _DataType::channels; ++px )
							val[ px ] += pixel[ px ];
					}

			_DataType& pixel = _data.m_target.at< _DataType >( i * _data.m_target.cols + j );
			for ( int px = 0; px < _DataType::channels; ++px )
				pixel[ px ] = static_cast< _DataType::value_type >( val[ px ] / rValue );
			}
	}

}
#include "task_utils.hpp"

namespace Tasks {
namespace Utils {

	void createBlurFilter(ObjectData& _data, int _filterSize, double _sigmaX)
	{
		_data.m_filter.reset(new float[_filterSize * _filterSize]);
		float* filterPtr = _data.m_filter.get();

		float filterSum = 0.f;
		const int halfWidth = _filterSize / 2;

		for (int r = -halfWidth; r <= halfWidth; ++r)
			for (int c = -halfWidth; c <= halfWidth; ++c)
			{
				float filterValue = expf(-(float)(c * c + r * r) / (float)(2.f * _sigmaX * _sigmaX));
				filterPtr[(r + halfWidth) * _filterSize + c + halfWidth] = filterValue;
				filterSum += filterValue;
			}

		float normalizationFactor = 1.f / filterSum;

		for (int r = -halfWidth; r <= halfWidth; ++r)
			for (int c = -halfWidth; c <= halfWidth; ++c)
				filterPtr[(r + halfWidth) * _filterSize + c + halfWidth] *= normalizationFactor;
	}

	float calculateThresholdValue( ObjectData& _data )
	{
		int histogram[256];
		memset( histogram, 0, sizeof(int) * 256 );

		const int pixelsCount = _data.m_source.cols * _data.m_source.rows;
		for ( int i = 0; i < _data.m_source.rows; ++i )
		{
			for ( int j = 0; j < _data.m_source.cols; ++j )
			{
				auto& sourcePixel = _data.m_source.at< cv::Vec4b >( i, j );

				uchar grayPixelValue =
					( sourcePixel.val[0] * 307 +
					  sourcePixel.val[1] * 604 +
					  sourcePixel.val[2] * 113 ) >> 10;

				++histogram[ grayPixelValue ];
			}
		}

		float sum = 0;
		for (int i = 1; i < 256; ++i)
			sum += i * histogram[i];

		float sumB = 0, wB = 0, wF = 0, mB = 0, mF = 0;
		float max = 0.0, between = 0.0, threshold1 = 0.0, threshold2 = 0.0;

		for (int i = 0; i < 256; ++i)
		{
			wB += histogram[i];
			if (wB == 0)
				continue;
			wF = pixelsCount - wB;
			if (wF == 0)
				break;
			sumB += i * histogram[i];
			mB = sumB / wB;
			mF = (sum - sumB) / wF;
			between = wB * wF * (mB - mF) * (mB - mF);
			if ( between >= max )
			{
				threshold1 = (float)i;
				if ( between > max )
				{
					threshold2 = (float)i;
				}
				max = between;
			}
		}

		return (float)( ( threshold1 + threshold2 ) / 2.0 );
	}
}
}
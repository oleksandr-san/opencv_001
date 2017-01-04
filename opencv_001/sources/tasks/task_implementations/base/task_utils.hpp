#ifndef __TASK_UTILS_HPP__
#define __TASK_UTILS_HPP__

#include "sources/tasks/task_implementations/base/object_data.hpp"

namespace Tasks {
namespace Utils {

	class FilterCreator
	{

	public:

		static void createBlurFilter( ObjectData& _data, int _filterSize, double _sigmaX )
		{
			_data.m_filter.reset( new float[_filterSize * _filterSize] );
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
	};

}
}

#endif
#ifndef __TASK_UTILS_HPP__
#define __TASK_UTILS_HPP__

#include "sources/tasks/task_implementations/base/object_data.hpp"

namespace Tasks {
namespace Utils {

	void createBlurFilter( ObjectData& _data, int _filterSize, double _sigmaX );

	float calculateThresholdValue( ObjectData& _data );
}
}

#endif
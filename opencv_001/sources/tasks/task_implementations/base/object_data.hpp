#ifndef __OBJECT_DATA_HPP__
#define __OBJECT_DATA_HPP__

#include <opencv2/core.hpp>
#include <opencv2/cudafilters.hpp>

#include <boost/scoped_array.hpp>

namespace Tasks {

	struct ObjectData
	{
		cv::Mat m_source, m_target;

		cv::cuda::GpuMat m_deviceSource, m_deviceTarget;

		boost::scoped_array< float > m_filter;
	};
}

#endif
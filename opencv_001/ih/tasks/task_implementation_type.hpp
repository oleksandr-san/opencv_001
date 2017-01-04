#ifndef __TASK_IMPLEMENTATION_TYPE_HPP__
#define __TASK_IMPLEMENTATION_TYPE_HPP__

#include "ih/exceptions/exceptions.hpp"

#include <boost/lexical_cast.hpp>

namespace Tasks {

	struct TaskImplementationType
	{
		enum Enum
		{
				Custom		= 0
			,	Custom_CUDA
			,	OpenCV
			,	OpenCV_CUDA
			,	OpenMP

			,	Last
			,	First = Custom
		};

		static const char * getName( Enum _enum )
		{
			switch( _enum )
			{
			case Custom:
				return "Custom";

			case Custom_CUDA:
				return "Custom CUDA";

			case OpenCV:
				return "OpenCV";

			case OpenCV_CUDA:
				return "OpenCV CUDA";

			case OpenMP:
				return "OpenMP";

			default:
				return nullptr;
			}
		}

		static const char * getCodeName( Enum _enum )
		{
			switch( _enum )
			{
			case Custom:
				return "custom";

			case Custom_CUDA:
				return "custom_cuda";

			case OpenCV:
				return "opencv";

			case OpenCV_CUDA:
				return "opencv_cuda";

			case OpenMP:
				return "openmp";

			default:
				return nullptr;
			}
		}

		static Enum fromInt( int _value )
		{
			switch( _value )
			{
			case 0:
				return Custom;

			case 1:
				return Custom_CUDA;

			case 2:
				return OpenCV;

			case 3:
				return OpenCV_CUDA;

			case 4:
				return OpenMP;

			default:
				throw Exceptions::InvalidParameterException(
					"Task Type",
					boost::lexical_cast< std::string >( _value )
				);
			}
		}
	};
}

#endif
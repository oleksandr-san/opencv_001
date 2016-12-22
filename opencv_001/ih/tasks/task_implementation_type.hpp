#ifndef __TASK_IMPLEMENTATION_TYPE_HPP__
#define __TASK_IMPLEMENTATION_TYPE_HPP__

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
				return "ppencv_cuda";

			case OpenMP:
				return "openmp";

			default:
				return nullptr;
			}
		}
	};
}

#endif
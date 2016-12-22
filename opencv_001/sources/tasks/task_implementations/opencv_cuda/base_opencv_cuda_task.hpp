#ifndef __BASE_OPENCV_CUDA_TASK_HPP__
#define __BASE_OPENCV_CUDA_TASK_HPP__

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/cudafilters.hpp>

#include "sources/tasks/task_implementations/base/base_typed_task.hpp"

namespace Tasks {

	template < TaskType::Enum _Type >
	class Base_OpenCV_CUDA_Task
		:	public BaseTypedTask<
					_Type,
					TaskImplementationType::OpenCV_CUDA
				>
	{

		typedef
			BaseTypedTask<
				_Type,
				TaskImplementationType::OpenCV_CUDA
			>
			BaseClass;

	public:

		Base_OpenCV_CUDA_Task( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual void runInternal( TaskContext& _context ) override
		{
			cv::Mat host_source;
			loadObject( host_source, _context );

			cv::cuda::GpuMat device_source;
			device_source.upload( host_source );

			cv::cuda::GpuMat device_target;

			processObject( host_source, device_source, device_target );

			cv::Mat host_target;
			device_target.download( host_target );

			saveObject( host_target, _context );
		}

		virtual void processObject(
				cv::Mat& _hostSource,
				cv::cuda::GpuMat& _deviceSource,
				cv::cuda::GpuMat& _deviceTarget
			) = 0;

	};

}

#endif

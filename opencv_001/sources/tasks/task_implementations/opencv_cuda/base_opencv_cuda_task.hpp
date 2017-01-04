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

		virtual void runInternal( ObjectData& _data )
		{
			processObject( _data.m_source, _data.m_deviceSource, _data.m_deviceTarget );
		}

		virtual void processObject(
				cv::Mat& _hostSource,
				cv::cuda::GpuMat& _deviceSource,
				cv::cuda::GpuMat& _deviceTarget
			) = 0;


		virtual void prepareObjectData( ObjectData& _data, TaskContext& _context )
		{
			BaseClass::prepareObjectData( _data, _context );

			_data.m_deviceSource.upload( _data.m_source );
		}

		virtual void saveObjectData( ObjectData& _data, TaskContext& _context )
		{
			_data.m_deviceTarget.download( _data.m_target );

			BaseClass::saveObjectData( _data, _context );
		}

	};

}

#endif

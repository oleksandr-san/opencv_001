#include "sources/tasks/task_implementations/custom_cuda/custom_cuda_task.hpp"
#include "sources/tasks/task_implementations/base/task_utils.hpp"

#include "cudah/image_processing.hpp"

namespace Tasks {
	
	template < TaskType::Enum _Type >
	CustomCUDATask< _Type >::CustomCUDATask( 
			ITaskProperties::Ptr _properties
	)
		:	BaseClass( _properties )
	{
	}

	template <>
	void
	CustomCUDATask< TaskType::Grayscale >::runInternal( ObjectData& _data )
	{
		if ( getProperties().getOptimizeBlockProcessing() )
		{
			ExecuteGrayscaleCUDASimple(
				_data.m_deviceSource,
				_data.m_deviceTarget
			);
		}
		else
		{
			ExecuteGrayscaleCUDASimple(
				_data.m_deviceSource,
				_data.m_deviceTarget
			);
		}
	}

	template <>
	void
	CustomCUDATask< TaskType::Blur >::runInternal( ObjectData& _data )
	{
		ExecuteGaussianBlur(
			_data.m_deviceSource,
			_data.m_deviceTarget,
			_data.m_filter.get(),
			getProperties().getBlurringKernelSize()
		);
	}

	template < TaskType::Enum _Type >
	void
	CustomCUDATask< _Type >::prepareObjectData( ObjectData& _data, TaskContext& _context )
	{
		BaseClass::prepareObjectData( _data, _context );

		_data.m_deviceSource.upload( _data.m_source );
		_data.m_deviceTarget.create(
				_data.m_deviceSource.rows,
				_data.m_deviceSource.cols,
				_data.m_deviceSource.type()
			);
	}

	template <>
	void
	CustomCUDATask< TaskType::Blur >::prepareObjectData( ObjectData& _data, TaskContext& _context )
	{
		BaseClass::prepareObjectData( _data, _context );

		_data.m_deviceSource.upload( _data.m_source );
		_data.m_deviceTarget.create(
				_data.m_deviceSource.rows,
				_data.m_deviceSource.cols,
				_data.m_deviceSource.type()
			);

		Utils::FilterCreator::createBlurFilter(
			_data,
			getProperties().getBlurringKernelSize(),
			getProperties().getSigmaX()
		);
	}

	template < TaskType::Enum _Type >
	void
	CustomCUDATask< _Type >::saveObjectData( ObjectData& _data, TaskContext& _context )
	{
		_data.m_deviceTarget.download( _data.m_target );

		BaseClass::saveObjectData( _data, _context );
	}

	template class CustomCUDATask< TaskType::Grayscale >;
	template class CustomCUDATask< TaskType::Blur >;
}
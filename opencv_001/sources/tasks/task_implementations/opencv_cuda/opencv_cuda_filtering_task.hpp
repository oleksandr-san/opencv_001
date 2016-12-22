#ifndef __OPENCV_CUDA_FILTERING_TASK_HPP__
#define __OPENCV_CUDA_FILTERING_TASK_HPP__

#include <unordered_map>
#include <opencv2/cudafilters.hpp>

#include "sources/tasks/task_implementations/opencv_cuda/base_opencv_cuda_task.hpp"

namespace Tasks {

	template < TaskType::Enum _Type >
	class OpenCV_CUDA_FilteringTask
		:	public Base_OpenCV_CUDA_Task< _Type >
	{

		typedef
			Base_OpenCV_CUDA_Task< _Type >
			BaseClass;

	public:

		OpenCV_CUDA_FilteringTask( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual void processObject(
			cv::Mat& _hostSource,
			cv::cuda::GpuMat& _deviceSource,
			cv::cuda::GpuMat& _deviceTarget
		)
		{
			getFilter( _hostSource )->apply( _deviceSource, _deviceTarget );
		}

		cv::Ptr< cv::cuda::Filter > getFilter( cv::Mat& _matrix )
		{
			auto it = m_filters.find( _matrix.type() );
			if ( it != m_filters.end() )
				return it->second;

			cv::Ptr< cv::cuda::Filter > filter = createFilter( _matrix );

			m_filters[ _matrix.type() ] = filter;

			return filter;
		}

		virtual cv::Ptr< cv::cuda::Filter > createFilter( cv::Mat& _matrix ) = 0;

	private:

		std::unordered_map< int, cv::Ptr< cv::cuda::Filter > > m_filters;

	};


	class OpenCV_CUDA_BoxFilter_Task
		:	public OpenCV_CUDA_FilteringTask< TaskType::BoxFilter >
	{

	typedef
		OpenCV_CUDA_FilteringTask< TaskType::BoxFilter >
		BaseClass;

	public:

		OpenCV_CUDA_BoxFilter_Task( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual cv::Ptr< cv::cuda::Filter > createFilter( cv::Mat& _matrix ) override;

	};


	class OpenCV_CUDA_SobelFilter_Task
		:	public OpenCV_CUDA_FilteringTask< TaskType::SobelFilter >
	{

	typedef
		OpenCV_CUDA_FilteringTask< TaskType::SobelFilter >
		BaseClass;

	public:

		OpenCV_CUDA_SobelFilter_Task( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual cv::Ptr< cv::cuda::Filter > createFilter( cv::Mat& _matrix ) override;

	};
}

#endif
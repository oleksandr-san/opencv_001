#ifndef __OPENCV_CUDA_IMAGE_PROCESSING_TASK_HPP__
#define __OPENCV_CUDA_IMAGE_PROCESSING_TASK_HPP__

#include <opencv2/core.hpp>
#include <unordered_map>
#include "sources/tasks/task_implementations/opencv_cuda/base_opencv_cuda_task.hpp"

namespace Tasks {

	class OpenCV_CUDA_GrayscaleTask
		:	public Base_OpenCV_CUDA_Task< TaskType::Grayscale >
	{

		typedef
			Base_OpenCV_CUDA_Task< TaskType::Grayscale >
			BaseClass;

	public:

		OpenCV_CUDA_GrayscaleTask( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual void processObject(
			cv::Mat& _hostSource,
			cv::cuda::GpuMat& _deviceSource,
			cv::cuda::GpuMat& _deviceTarget
			) override;

	};


	class OpenCV_CUDA_BinarizationTask
		:	public Base_OpenCV_CUDA_Task< TaskType::Binarization >
	{

		typedef
			Base_OpenCV_CUDA_Task< TaskType::Binarization >
			BaseClass;

	public:

		OpenCV_CUDA_BinarizationTask( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual void processObject(
			cv::Mat& _hostSource,
			cv::cuda::GpuMat& _deviceSource,
			cv::cuda::GpuMat& _deviceTarget
		) override;

	};


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
			//auto it = m_filters.find( _matrix.type() );
			//if ( it != m_filters.end() )
			//	return it->second;

			//cv::Ptr< cv::cuda::Filter > filter = createFilter( _matrix );

			//m_filters[ _matrix.type() ] = filter;

			return createFilter( _matrix );
		}

		virtual cv::Ptr< cv::cuda::Filter > createFilter( cv::Mat& _matrix ) = 0;

	private:

		std::unordered_map< int, cv::Ptr< cv::cuda::Filter > > m_filters;

	};


	class OpenCV_CUDA_BlurTask
		:	public OpenCV_CUDA_FilteringTask< TaskType::Blur >
	{

	typedef
		OpenCV_CUDA_FilteringTask< TaskType::Blur >
		BaseClass;

	public:

		OpenCV_CUDA_BlurTask( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

	protected:

		virtual cv::Ptr< cv::cuda::Filter > createFilter( cv::Mat& _matrix ) override;

	};

}

#endif
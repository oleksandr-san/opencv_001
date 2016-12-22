#include "sources/tasks/task_manager.hpp"
#include "sources/tasks/task_properties.hpp"

#include "sources/tasks/task_implementations/custom/custom_image_processing_task.hpp"
#include "sources/tasks/task_implementations/custom/custom_box_filter_task.hpp"
#include "sources/tasks/task_implementations/custom/custom_sobel_filter_task.hpp"
#include "sources/tasks/task_implementations/opencv/opencv_filtering_task.hpp"
#include "sources/tasks/task_implementations/opencv/opencv_image_processing_task.hpp"
#include "sources/tasks/task_implementations/opencv_cuda/opencv_cuda_filtering_task.hpp"
#include "sources/tasks/task_implementations/opencv_cuda/opencv_cuda_image_processing_task.hpp"
#include "sources/tasks/task_implementations/openmp/openmp_box_filter_task.hpp"
#include "sources/tasks/task_implementations/openmp/openmp_sobel_filter_task.hpp"
#include "sources/tasks/task_implementations/openmp/openmp_image_processing_task.hpp"
#include "sources/tasks/task_implementations/custom_cuda/custom_cuda_task.hpp"

namespace Tasks {

	ITask::Ptr TaskManager::createTask(
		TaskType::Enum _type,
		TaskImplementationType::Enum _implementationType
	)
	{
		switch (_type)
		{
		case TaskType::Grayscale:
		{
			switch (_implementationType)
			{
			case TaskImplementationType::Custom:
				return createTaskInternal< CustomGrayscaleTask >();

			case TaskImplementationType::Custom_CUDA:
				return createTaskInternal< GrayscaleCUDA >();

			case TaskImplementationType::OpenCV:
				return createTaskInternal< OpenCV_Grayscale_Task >();

			case TaskImplementationType::OpenCV_CUDA:
				return createTaskInternal< OpenCV_CUDA_GrayscaleTask >();

			case TaskImplementationType::OpenMP:
				return createTaskInternal< OpenMPGrayscaleTask >();

			default:
				throw std::invalid_argument("Invalid implementation type!");
			}
			break;
		}

		case TaskType::BoxFilter:
		{
			switch (_implementationType)
			{
			case TaskImplementationType::Custom:
				return createTaskInternal< CustomBoxFilterTask >();

			case TaskImplementationType::Custom_CUDA:
				return createTaskInternal< BoxFilterCUDA >();

			case TaskImplementationType::OpenCV:
				return createTaskInternal< OpenCV_BoxFilter_Task >();

			case TaskImplementationType::OpenCV_CUDA:
				return createTaskInternal< OpenCV_CUDA_BoxFilter_Task >();

			case TaskImplementationType::OpenMP:
				return createTaskInternal< OpenMPBoxFilterTask >();

			default:
				throw std::invalid_argument("Invalid implementation type!");
			}
			break;
		}

		case TaskType::SobelFilter:
		{
			switch (_implementationType)
			{
			case TaskImplementationType::Custom:
				return createTaskInternal< CustomSobelFilterTask >();

			case TaskImplementationType::Custom_CUDA:
				return createTaskInternal< SobelFilterCUDA >();

			case TaskImplementationType::OpenCV:
				return createTaskInternal< OpenCV_SobelFilter_Task >();

			case TaskImplementationType::OpenCV_CUDA:
				return createTaskInternal< OpenCV_CUDA_SobelFilter_Task >();

			case TaskImplementationType::OpenMP:
				return createTaskInternal< OpenMPSobelFilterTask >();

			default:
				throw std::invalid_argument("Invalid implementation type!");
			}
			break;
		}

		default:
			throw std::invalid_argument("Invalid task kind!");
		}
	}

	template< typename _TaskType >
	ITask::Ptr Tasks::TaskManager::createTaskInternal()
	{
		return ITask::Ptr(
				new _TaskType(
					ITaskProperties::Ptr( new TaskProperties() )
				)
			);
	}
}
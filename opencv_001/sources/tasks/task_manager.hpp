#ifndef __TASK_MANAGER_HPP__
#define __TASK_MANAGER_HPP__

#include "ih/tasks/itask_manager.hpp"

namespace Tasks {

	class TaskManager
		: public ITaskManager
	{

	public:

		virtual ITask::Ptr createTask(
				TaskType::Enum _type,
				TaskImplementationType::Enum _implementationType
			) override;

	private:
	
		template < typename _TaskType > ITask::Ptr createTaskInternal();

	};

}

#endif
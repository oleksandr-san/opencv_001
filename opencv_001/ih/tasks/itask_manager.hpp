#ifndef __ITASK_MANAGER_HPP__
#define __ITASK_MANAGER_HPP__

#include "ih/tasks/itask.hpp"

namespace Tasks {

	class ITaskManager : boost::noncopyable
	{

	public:

		typedef std::shared_ptr< ITaskManager > Ptr;

	public:

		virtual ITask::Ptr createTask(
				TaskType::Enum _type,
				TaskImplementationType::Enum _implementationType
			) = 0;
	};
}

#endif
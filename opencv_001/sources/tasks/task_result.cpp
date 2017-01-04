#include "task_result.hpp"

namespace Tasks {



	TaskResult::TaskResult( std::shared_ptr< ITask > _task)
		:	m_task( _task )
	{
	}

	const ITaskResult::ObjectResultList&
	TaskResult::getObjectResults() const
	{
		return m_results;
	}

	const ITask& TaskResult::getTask() const
	{
		return *m_task;
	}

	TaskResult::ObjectResultList&
	TaskResult::takeObjectResults()
	{
		return m_results;
	}

}

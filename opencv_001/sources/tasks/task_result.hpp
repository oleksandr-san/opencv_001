#ifndef __TASK_RESULT_HPP__
#define __TASK_RESULT_HPP__

#include "ih/tasks/itask_result.hpp"

namespace Tasks {

	class TaskResult
		: public ITaskResult
	{

	public:

		TaskResult( std::shared_ptr< ITask > _task );

		virtual const ObjectResultList&	getObjectResults() const override;

		virtual const ITask& getTask() const override;

	public:

		ObjectResultList& takeObjectResults();

	private:

		ITaskResult::ObjectResultList m_results;

		std::shared_ptr< ITask > m_task;

	};

}

#endif
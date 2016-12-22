#ifndef __TASK_RESULT_HPP__
#define __TASK_RESULT_HPP__

#include "ih/tasks/itask_result.hpp"

namespace Tasks {

	class TaskResult
		: public ITaskResult
	{

	public:

		TaskResult();

		virtual const Utils::TimePoint& getStartTime() const override;

		virtual const Utils::TimePoint& getEndTime() const override;

		virtual void setStartTime( const Utils::TimePoint& _timePoint ) override;

		virtual void setEndTime( const Utils::TimePoint& _timePoint ) override;

	private:

		Utils::TimePoint m_startTime, m_endTime;

	};

}

#endif
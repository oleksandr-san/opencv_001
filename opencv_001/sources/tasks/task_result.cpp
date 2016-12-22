#include "task_result.hpp"

namespace Tasks {

	TaskResult::TaskResult()
	{
	}

	const Utils::TimePoint& TaskResult::getStartTime() const
	{
		return m_startTime;
	}

	const Utils::TimePoint& TaskResult::getEndTime() const
	{
		return m_endTime;
	}

	void TaskResult::setStartTime( const Utils::TimePoint& _timePoint )
	{
		m_startTime = _timePoint;
	}

	void TaskResult::setEndTime( const Utils::TimePoint& _timePoint )
	{
		m_endTime = _timePoint;
	}

}

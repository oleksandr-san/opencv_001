#ifndef __ITASK_RESULT_HPP__
#define __ITASK_RESULT_HPP__

#include "ih/utils/utils.hpp"

namespace Tasks {

	class ITaskResult : boost::noncopyable
	{

	public:

		typedef std::shared_ptr< ITaskResult > Ptr;

	public:

		virtual const Utils::TimePoint& getStartTime() const = 0;

		virtual const Utils::TimePoint& getEndTime() const = 0;

		virtual void setStartTime( const Utils::TimePoint& _timePoint ) = 0;

		virtual void setEndTime( const Utils::TimePoint& _timePoint ) = 0;

	};

}

#endif
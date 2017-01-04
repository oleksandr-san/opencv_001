#ifndef __ITASK_RESULT_HPP__
#define __ITASK_RESULT_HPP__

#include "ih/utils/utils.hpp"
#include "ih/objects/iprocessing_object.hpp"

namespace Tasks {

	class ITask;

	class ITaskResult : boost::noncopyable
	{

	public:

		typedef std::shared_ptr< ITaskResult > Ptr;

		typedef
			std::pair< Utils::TimePoint, Utils::TimePoint >
			TimePointPair;

		struct TimeResult
		{
			TimePointPair m_loadTime;
			TimePointPair m_processTime;
			TimePointPair m_saveTime;
		};

		typedef
			std::pair<
					Objects::IProcessingObject::Ptr
				,	std::vector< TimeResult >
			>
			ObjectResult;

		typedef
			std::vector< ObjectResult >
			ObjectResultList;

	public:

		virtual const ObjectResultList&	getObjectResults() const = 0;

		virtual const ITask& getTask() const = 0;
	};

}

#endif
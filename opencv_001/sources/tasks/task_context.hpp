#ifndef __TASK_CONTEXT_HPP__
#define __TASK_CONTEXT_HPP__

#include "ih/objects/iprocessing_object.hpp"

namespace Tasks {

	class TaskContext
	{

	public:

		int getIteration()
		{
			return m_iteration;
		}

		Objects::IProcessingObject::Ptr getObject()
		{
			return m_object;
		}

		void setIteration( int _iteration )
		{
			m_iteration = _iteration;
		}

		void setObject( Objects::IProcessingObject::Ptr _object )
		{
			m_object = _object;
		}

	private:

		Objects::IProcessingObject::Ptr m_object;
		int m_iteration;

	};

}

#endif
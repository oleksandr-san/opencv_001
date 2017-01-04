#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "ih/tasks/itask.hpp"
#include "sources/tasks/task_context.hpp"
#include "sources/tasks/task_implementations/base/object_data.hpp"


namespace Tasks {

	class BaseTask
		:	public ITask
		,	std::enable_shared_from_this< BaseTask >
	{

	public:

		BaseTask( ITaskProperties::Ptr _properties );

		virtual ITaskResult::Ptr run(
				Objects::IProcessingObject::List _objects
			) override;

		virtual ITaskProperties& getProperties() const override;

		virtual ITaskProperties& takeProperties() override;

	protected:

		virtual void runInternal( ObjectData& _data ) = 0;

		virtual void prepareObjectData( ObjectData& _data, TaskContext& _context );

		virtual void saveObjectData( ObjectData& _data, TaskContext& _context );

	private:

		ITaskProperties::Ptr m_properties;

	};

}

#endif
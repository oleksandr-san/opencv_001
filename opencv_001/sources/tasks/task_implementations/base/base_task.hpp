#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "ih/tasks/itask.hpp"
#include "sources/tasks/task_context.hpp"

#include <opencv2/core.hpp>

namespace Tasks {

	class BaseTask
		: public ITask
	{

	public:

		BaseTask( ITaskProperties::Ptr _properties );

		virtual ITaskResult::Ptr run(
				Objects::IProcessingObject::List _objects
			) override;

		virtual ITaskProperties& getProperties() override;

	protected:

		virtual ITaskResult::Ptr getResult();

		virtual void runInternal( TaskContext& _context ) = 0;

		virtual void loadObject( cv::Mat& _target, TaskContext& _context );

		virtual void saveObject( cv::Mat& _source, TaskContext& _context );

	private:

		ITaskProperties::Ptr m_properties;

	};

}

#endif
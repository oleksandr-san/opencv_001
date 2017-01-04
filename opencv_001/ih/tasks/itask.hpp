#ifndef __ITASK_HPP__
#define __ITASK_HPP__

#include "ih/utils/utils.hpp"
#include "ih/tasks/itask_result.hpp"
#include "ih/tasks/itask_properties.hpp"
#include "ih/tasks/task_type.hpp"
#include "ih/tasks/task_implementation_type.hpp"
#include "ih/objects/iprocessing_object.hpp"

namespace Tasks {

	class ITask : boost::noncopyable
	{

	public:

		typedef std::shared_ptr< ITask > Ptr;

	public:

		virtual TaskType::Enum getType() const = 0;

		virtual TaskImplementationType::Enum getImplementationType() const = 0;

		virtual ITaskProperties& getProperties() const = 0;
		
		virtual ITaskProperties& takeProperties() = 0;

		virtual ITaskResult::Ptr run(
				Objects::IProcessingObject::List _objects
			) = 0;

	};
}

#endif
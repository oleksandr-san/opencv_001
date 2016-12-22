#ifndef __BASE_TYPED_TASK_HPP__
#define __BASE_TYPED_TASK_HPP__

#include "sources/tasks/task_implementations/base/base_task.hpp"

namespace Tasks {

	template <
			TaskType::Enum _Type
		,	TaskImplementationType::Enum _ImplementationType
	>
	class BaseTypedTask :
		public BaseTask
	{

		typedef
			BaseTask
			BaseClass;

	public:

		BaseTypedTask( ITaskProperties::Ptr _properties )
			:	BaseClass( _properties )
		{
		}

		virtual TaskType::Enum getType() const override
		{
			return _Type;
		}

		virtual TaskImplementationType::Enum getImplementationType() const override
		{
			return _ImplementationType;
		}

	};

}

#endif
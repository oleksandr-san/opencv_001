#pragma once

#include "opencv_001/ih/accessor/accessor.hpp"

class RunManager
{

public:

	typedef
		std::vector< std::string >
		ObjectList;

public:

	Tasks::ITaskResult::Ptr runTask(
			const ObjectList& _objects,
			Tasks::TaskType::Enum _type,
			Tasks::TaskImplementationType::Enum _implType,
			int _repeatsCount,
			int _blurringKernelSize,
			double _sigmaX,
			std::string _outputDirectory,
			bool _modifyOriginal,
			bool _optimizeBlockProcessing
		);


private:

	void convertObjects(
			Objects::IProcessingObject::List& _target,
			const ObjectList& _source
		);

	Tasks::ITaskManager& getTaskManager();

	Objects::IObjectsController& getObjectsController();

private:

	Acessor m_accesor;

	Tasks::ITaskManager::Ptr m_taskManager;

	Objects::IObjectsController::Ptr m_objectsController;
};
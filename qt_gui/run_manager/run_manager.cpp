#include "run_manager.hpp"

#include <thread>

Tasks::ITaskResult::Ptr
RunManager::runTask(
	const ObjectList& _objects,
	Tasks::TaskType::Enum _type,
	Tasks::TaskImplementationType::Enum _implType,
	int _repeatsCount,
	int _blurringKernelSize,
	double _sigmaX,
	std::string _outputDirectory,
	bool _modifyOriginal,
	bool _optimizeBlockProcessing
)
{
	using namespace Tasks;
	using namespace Objects;

	ITask::Ptr task = getTaskManager().createTask( _type, _implType );

	if ( task )
	{
		ITaskProperties& properties = task->takeProperties();

		properties.setRepeatsCount( _repeatsCount );
		properties.setBlurringKernelSize( _blurringKernelSize );
		properties.setSigmaX( _sigmaX );
		properties.setOutputDirectory( _outputDirectory );
		properties.setModifyOriginal( _modifyOriginal );
		properties.setOptimizeBlockProcessing( _optimizeBlockProcessing );

		IProcessingObject::List objects;
		convertObjects( objects, _objects );

		return task->run( objects );
	}

	return Tasks::ITaskResult::Ptr();
}

void RunManager::convertObjects(
	Objects::IProcessingObject::List & _target,
	const ObjectList & _source
)
{
	for ( auto object : _source )
	{
		Utils::Path objectPath( object );

		if ( !Filesystem::exists( objectPath ) )
			throw Exceptions::MissingFileException( object );

		_target.push_back(
				getObjectsController().createProcessingObject(
					objectPath
				)
			);
	}
}

Tasks::ITaskManager & RunManager::getTaskManager()
{
	if ( !m_taskManager )
	{
		m_taskManager = m_accesor.createTaskManager();
	}

	return *m_taskManager;
}

Objects::IObjectsController & RunManager::getObjectsController()
{
	if ( !m_objectsController )
	{
		m_objectsController = m_accesor.createObjectsController();
	}

	return *m_objectsController;
}

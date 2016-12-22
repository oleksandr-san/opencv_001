#include "ih/accessor/accessor.hpp"
#include "sources/tasks/task_manager.hpp"
#include "sources/objects/objects_controller.hpp"

Tasks::ITaskManager::Ptr
Acessor::createTaskManager()
{
	return Tasks::ITaskManager::Ptr( new Tasks::TaskManager() );
}

Objects::IObjectsController::Ptr
Acessor::createObjectsController()
{
	return Objects::IObjectsController::Ptr( new Objects::ObjectsController() );
}

#ifndef __ACCESSOR_HPP__
#define __ACCESSOR_HPP__

#include "ih/tasks/itask_manager.hpp"
#include "ih/objects/iobjects_controller.hpp"

class Acessor
{

public:

	Tasks::ITaskManager::Ptr createTaskManager();

	Objects::IObjectsController::Ptr createObjectsController();
};

#endif
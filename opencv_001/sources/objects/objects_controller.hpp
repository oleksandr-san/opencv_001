#ifndef __OBJECTS_CONTROLLER_HPP__
#define __OBJECTS_CONTROLLER_HPP__

#include "ih/objects/iobjects_controller.hpp"

namespace Objects {

	class ObjectsController 
		: public IObjectsController
	{

	public:
	
		virtual IProcessingObject::Ptr createProcessingObject(
				const Utils::Path & _path
			) override;

	};
}

#endif
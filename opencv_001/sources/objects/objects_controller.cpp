#include "sources/objects/objects_controller.hpp"
#include "sources/objects/processing_object.hpp"

namespace Objects {

	IProcessingObject::Ptr
	ObjectsController::createProcessingObject(const Utils::Path & _path)
	{
		return std::shared_ptr< IProcessingObject >(
				new ProcessingObject( _path )
			);
	}

}
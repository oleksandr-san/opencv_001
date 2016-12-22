#ifndef __IOBJECTS_CONTROLLER_HPP__
#define __IOBJECTS_CONTROLLER_HPP__

#include <boost/noncopyable.hpp>

#include "ih/objects/iprocessing_object.hpp"

namespace Objects {

	class IObjectsController : boost::noncopyable
	{
	
	public:

		typedef std::shared_ptr< IObjectsController > Ptr;
	
	public:

		virtual IProcessingObject::Ptr createProcessingObject(
				const Utils::Path& _path
			) = 0;

	};
}

#endif
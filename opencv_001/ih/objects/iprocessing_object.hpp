#ifndef __IPROCESSING_OBJECT_HPP__
#define __IPROCESSING_OBJECT_HPP__

#include "ih/utils/utils.hpp"

namespace Objects {

	class IProcessingObject : boost::noncopyable
	{

	public:

		typedef std::shared_ptr< IProcessingObject > Ptr;

		typedef std::vector< Ptr > List;

	public:

		virtual const Utils::Path& getPath() const = 0;

	};
}

#endif
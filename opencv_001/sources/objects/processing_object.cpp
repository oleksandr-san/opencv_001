#include "sources/objects/processing_object.hpp"

namespace Objects {

	ProcessingObject::ProcessingObject( const Utils::Path& _path )
		:	m_path( _path )
	{
	}

	const Utils::Path& ProcessingObject::getPath() const
	{
		return m_path;
	}
}
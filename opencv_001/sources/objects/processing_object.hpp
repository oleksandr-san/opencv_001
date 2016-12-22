#ifndef __PROCESSING_OBJECT_HPP__
#define __PROCESSING_OBJECT_HPP__

#include "ih/objects/iprocessing_object.hpp"

namespace Objects {

	class ProcessingObject
		: public IProcessingObject
	{

	public:

		ProcessingObject( const Utils::Path& _path );

		virtual const Utils::Path& getPath() const override;

	private:

		Utils::Path m_path;

	};

}

#endif
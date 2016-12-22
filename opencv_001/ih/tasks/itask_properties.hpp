#ifndef __ITASK_PROPERTIES_HPP__
#define __ITASK_PROPERTIES_HPP__

#include <boost/any.hpp>
#include <boost/optional.hpp>

#include "ih/utils/utils.hpp"

namespace Tasks {

	struct TaskProperty
	{
		enum Enum
		{
				RepeatsCount = 0
			,	OutputDirectory
			,	KernelSize
		};
	};

	class ITaskProperties : boost::noncopyable
	{

	public:

		typedef std::shared_ptr< ITaskProperties > Ptr;

	public:

		virtual boost::optional< int > getIntProperty(
				TaskProperty::Enum _property
			) const = 0;

		virtual boost::optional< std::string > getStringProperty(
				TaskProperty::Enum _property
			) const = 0;

		virtual boost::optional< Utils::Path > getPathProperty(
				TaskProperty::Enum _property
			) const = 0;

		virtual void setProperty( 
				TaskProperty::Enum _property
			,	const boost::any& _value
			) = 0;

		virtual void resetProperties() = 0;
	};
}

#endif
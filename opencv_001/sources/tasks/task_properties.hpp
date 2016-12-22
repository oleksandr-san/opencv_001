#ifndef __TASK_PROPERTIES_HPP__
#define __TASK_PROPERTIES_HPP__

#include <unordered_map>

#include "ih/tasks/itask_properties.hpp"

namespace Tasks {

	class TaskProperties
		: public ITaskProperties
	{

	public:

		virtual boost::optional< int > getIntProperty(
				TaskProperty::Enum _property
			) const override;

		virtual boost::optional< std::string > getStringProperty(
				TaskProperty::Enum _property
			) const override;

		virtual boost::optional< Utils::Path > getPathProperty(
				TaskProperty::Enum _property
			) const override;

		virtual void setProperty( 
				TaskProperty::Enum _property
			,	const boost::any& _value
			) override;

		virtual void resetProperties() override;

	private:

		template < typename _ValueType >
		boost::optional< _ValueType > getTypedProperty(
				TaskProperty::Enum _property
			) const;

	private:

		std::unordered_map< TaskProperty::Enum, boost::any > m_values;

	};

}

#endif
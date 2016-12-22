#include "sources/tasks/task_properties.hpp"

namespace Tasks {

	boost::optional< int > 
	TaskProperties::getIntProperty(TaskProperty::Enum _property) const
	{
		return getTypedProperty< int >( _property );
	}

	boost::optional< std::string >
	TaskProperties::getStringProperty(TaskProperty::Enum _property) const
	{
		return getTypedProperty< std::string >( _property );
	}

	boost::optional< Utils::Path >
	TaskProperties::getPathProperty(TaskProperty::Enum _property) const
	{
		return getTypedProperty< Utils::Path >( _property );
	}

	void TaskProperties::setProperty(
			TaskProperty::Enum _property
		,	const boost::any & _value
		)
	{
		m_values[ _property ] = _value;
	}

	void TaskProperties::resetProperties()
	{
		m_values.clear();
	}

	template< typename _ValueType >
	boost::optional< _ValueType >
	TaskProperties::getTypedProperty( TaskProperty::Enum _property ) const
	{
		auto it = m_values.find( _property );
		if ( it != m_values.end() )
		{
			if ( auto value = boost::any_cast< _ValueType >( &it->second ) )
				return boost::optional< _ValueType >( *value );
		}
		return boost::optional< _ValueType >();
	}

}
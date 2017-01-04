#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include <exception>

namespace Exceptions {

	class BaseException : public std::runtime_error
	{

	public:

		BaseException( const std::string& _value )
			:	std::runtime_error( _value )
		{}

	};

	class InvalidParameterException : public BaseException
	{

	public:

		InvalidParameterException(
			const std::string& parameter,
			const std::string& value
		)
			:	BaseException( "\'" + value + "\' value is invalid for \'" + parameter + "\' parameter" )
		{
		}

	};

	class OpenFileError : public BaseException
	{

	public:

		OpenFileError( const std::string& _filePath )
			:	BaseException( "Can't open file \'" + _filePath + "\'. File is broken or missing" )
		{
		}

	};

	class MissingFileException : public BaseException
	{

	public:

		MissingFileException( const std::string& _filePath )
			:	BaseException( "File \'" + _filePath + "\'is missing" )
		{
		}

	};
}

#endif
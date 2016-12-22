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

	class OpenFileError : public BaseException
	{

	public:

		OpenFileError( const std::string& _filePath )
			:	BaseException( "Can't open file \'" + _filePath + "\'. File is broken or missing" )
		{
		}

	};

}

#endif
#ifndef __TASK_TYPE_HPP__
#define __TASK_TYPE_HPP__

#include "ih/exceptions/exceptions.hpp"

#include <boost/lexical_cast.hpp>

namespace Tasks {

	struct TaskType
	{
		enum Enum
		{
				Grayscale	= 0
			,	Binarization
			,	Blur

			,	Last
			,	First = Grayscale
		};

		static const char * getName( Enum _enum )
		{
			switch( _enum )
			{
			case Grayscale:
				return "Grayscale";

			case Binarization:
				return "Binarization";

			case Blur:
				return "Blur";

			default:
				return nullptr;
			}
		}

		static const char * getCodeName( Enum _enum )
		{
			switch( _enum )
			{
			case Grayscale:
				return "grayscale";

			case Binarization:
				return "binarization";

			case Blur:
				return "blur";

			default:
				return nullptr;
			}
		}

		static Enum fromInt( int _value )
		{
			switch( _value )
			{
			case 0:
				return Grayscale;

			case 1:
				return Binarization;

			case 2:
				return Blur;

			default:
				throw Exceptions::InvalidParameterException(
					"Task Type",
					boost::lexical_cast< std::string >( _value )
				);
			}
		}
	};
}

#endif
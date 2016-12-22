#ifndef __TASK_TYPE_HPP__
#define __TASK_TYPE_HPP__

namespace Tasks {

	struct TaskType
	{
		enum Enum
		{
				Grayscale	= 0
			,	BoxFilter
			,	SobelFilter

			,	Last
			,	First = Grayscale
		};

		static const char * getName( Enum _enum )
		{
			switch( _enum )
			{
			case Grayscale:
				return "Grayscale";

			case BoxFilter:
				return "Box Filter";

			case SobelFilter:
				return "Sobel Filter";

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

			case BoxFilter:
				return "boxfilter";

			case SobelFilter:
				return "sobelfilter";

			default:
				return nullptr;
			}
		}
	};
}

#endif
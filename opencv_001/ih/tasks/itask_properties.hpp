#ifndef __ITASK_PROPERTIES_HPP__
#define __ITASK_PROPERTIES_HPP__

#include <boost/any.hpp>
#include <boost/optional.hpp>

#include "ih/utils/utils.hpp"

namespace Tasks {

	class ITaskProperties : boost::noncopyable
	{

	public:

		typedef std::shared_ptr< ITaskProperties > Ptr;

	public:

		virtual int getRepeatsCount() const = 0;
		virtual const std::string& getOutputDirectory() const = 0;
		virtual int getBlurringKernelSize() const = 0;
		virtual double getSigmaX() const = 0;
		virtual bool getModifyOriginal() const = 0;
		virtual bool getOptimizeBlockProcessing() const = 0;

		virtual void setRepeatsCount(int _value) = 0;
		virtual void setOutputDirectory(const std::string& _value) = 0;
		virtual void setBlurringKernelSize(int _value) = 0;
		virtual void setSigmaX(double _value) = 0;
		virtual void setModifyOriginal(bool _value) = 0;
		virtual void setOptimizeBlockProcessing(bool _value) = 0;

		virtual void reset() = 0;
	};
}

#endif
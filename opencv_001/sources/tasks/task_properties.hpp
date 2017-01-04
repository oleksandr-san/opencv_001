#ifndef __TASK_PROPERTIES_HPP__
#define __TASK_PROPERTIES_HPP__

#include <unordered_map>

#include "ih/tasks/itask_properties.hpp"

namespace Tasks {

	class TaskProperties
		: public ITaskProperties
	{

	public:

		TaskProperties();

		virtual int getRepeatsCount() const;
		virtual const std::string& getOutputDirectory() const;
		virtual int getBlurringKernelSize() const;
		virtual double getSigmaX() const;
		virtual bool getModifyOriginal() const;
		virtual bool getOptimizeBlockProcessing() const;

		virtual void setRepeatsCount(int _value);
		virtual void setOutputDirectory(const std::string& _value);
		virtual void setBlurringKernelSize(int _value);
		virtual void setSigmaX(double _value);
		virtual void setModifyOriginal(bool _value);
		virtual void setOptimizeBlockProcessing(bool _value);

		virtual void reset() override;

	private:

		int m_repeatsCount;
		std::string m_outputDirectory;
		int m_blurringKernelSize;
		double m_sigmaX;
		bool m_modifyOriginal;
		bool m_optimizeBlockProcessing;

	};

}

#endif
#include "sources/tasks/task_properties.hpp"

namespace Tasks {



	TaskProperties::TaskProperties()
	{
		reset();
	}

	int TaskProperties::getRepeatsCount() const
	{
		return m_repeatsCount;
	}

	const std::string & TaskProperties::getOutputDirectory() const
	{
		return m_outputDirectory;
	}

	int TaskProperties::getBlurringKernelSize() const
	{
		return m_blurringKernelSize;
	}

	double TaskProperties::getSigmaX() const
	{
		return m_sigmaX;
	}

	bool TaskProperties::getModifyOriginal() const
	{
		return m_modifyOriginal;
	}

	bool TaskProperties::getOptimizeBlockProcessing() const
	{
		return m_optimizeBlockProcessing;
	}

	void TaskProperties::setRepeatsCount(int _value)
	{
		m_repeatsCount = _value;
	}

	void TaskProperties::setOutputDirectory(const std::string & _value)
	{
		m_outputDirectory = _value;
	}

	void TaskProperties::setBlurringKernelSize(int _value)
	{
		m_blurringKernelSize = _value;
	}

	void TaskProperties::setSigmaX(double _value)
	{
		m_sigmaX = _value;
	}

	void TaskProperties::setModifyOriginal(bool _value)
	{
		m_modifyOriginal = _value;
	}

	void TaskProperties::setOptimizeBlockProcessing(bool _value)
	{
		m_optimizeBlockProcessing = _value;
	}

	void TaskProperties::reset()
	{
		m_repeatsCount = 1;
		m_blurringKernelSize = 1;
		m_sigmaX = 1.0;
		m_modifyOriginal = false;
		m_outputDirectory.clear();
		m_optimizeBlockProcessing = false;
	}

}
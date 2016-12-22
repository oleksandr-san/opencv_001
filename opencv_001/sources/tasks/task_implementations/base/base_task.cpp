#include "sources/tasks/task_implementations/base/base_task.hpp"
#include "sources/tasks/task_result.hpp"

#include "ih/exceptions/exceptions.hpp"

#include <opencv2/imgcodecs.hpp>

namespace Tasks {

	BaseTask::BaseTask( ITaskProperties::Ptr _properties )
		:	m_properties( _properties )
	{
	}

	ITaskResult::Ptr BaseTask::run(
			Objects::IProcessingObject::List _objects
	)
	{
		Utils::TimePoint startTime = Utils::TimePoint::clock::now();

		auto property = getProperties().getIntProperty( TaskProperty::RepeatsCount );
		const int repeatsCount = property ? property.get() : 1;

		TaskContext context;

		for ( int i = 0; i < repeatsCount; ++i )
		{
			context.setIteration( i );

			for ( auto object : _objects )
			{
				context.setObject( object );

				runInternal( context );
			}
		}

		Utils::TimePoint endTime = Utils::TimePoint::clock::now();
	
		ITaskResult::Ptr result = getResult();

		result->setStartTime(startTime);
		result->setEndTime(endTime);

		return result;
	}

	ITaskProperties& BaseTask::getProperties()
	{
		return *m_properties;
	}

	ITaskResult::Ptr BaseTask::getResult()
	{
		return ITaskResult::Ptr( new TaskResult() );
	}

	void BaseTask::loadObject(cv::Mat & _target, TaskContext & _context)
	{
		const std::string path = _context.getObject()->getPath().string();

		_target = cv::imread( path );

		if ( !_target.data )
			throw Exceptions::OpenFileError( path );
	}

	void BaseTask::saveObject(cv::Mat & _source, TaskContext & _context)
	{
		auto outputDirectory = getProperties().getStringProperty(
				TaskProperty::OutputDirectory
			);

		if ( outputDirectory )
		{

		}
	}

}
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
		auto result = std::make_shared< TaskResult >( shared_from_this() );

		const int repeatsCount = getProperties().getRepeatsCount();

		ITaskResult::ObjectResultList& objectResults = result->takeObjectResults();

		for ( auto object : _objects )
			objectResults.push_back(
					ITaskResult::ObjectResult(
							object
						,	std::vector< ITaskResult::TimeResult >(
								static_cast< size_t >( repeatsCount )
							)
					)
				);

		TaskContext context;

		const size_t objectsCount = _objects.size();
		for ( int i = 0; i < repeatsCount; ++i )
		{
			context.setIteration( i );

			for ( int j = 0; j < objectsCount; ++j )
			{
				context.setObject( _objects[ j ] );
				ITaskResult::TimeResult& timeResult = objectResults[ j ].second[ i ];

				ObjectData data;

				timeResult.m_loadTime.first = Utils::TimePoint::clock::now();
				prepareObjectData( data, context );
				timeResult.m_loadTime.second = Utils::TimePoint::clock::now();

				timeResult.m_processTime.first = Utils::TimePoint::clock::now();
				runInternal( data );
				timeResult.m_processTime.second = Utils::TimePoint::clock::now();

				timeResult.m_saveTime.first = Utils::TimePoint::clock::now();
				saveObjectData( data, context );
				timeResult.m_saveTime.second = Utils::TimePoint::clock::now();
			}
		}

		return result;
	}

	ITaskProperties& BaseTask::getProperties() const
	{
		return *m_properties;
	}

	ITaskProperties& BaseTask::takeProperties()
	{
		return *m_properties;
	}

	void BaseTask::prepareObjectData(ObjectData& _data, TaskContext & _context)
	{
		const std::string path = _context.getObject()->getPath().string();
		_data.m_source = cv::imread( path, cv::IMREAD_COLOR  );
		if ( !_data.m_source.data )
			throw Exceptions::OpenFileError( path );

		cv::cvtColor( _data.m_source, _data.m_source, cv::COLOR_BGR2BGRA );

		_data.m_target.create(_data.m_source.rows, _data.m_source.cols, _data.m_source.type() );
	}

	void BaseTask::saveObjectData( ObjectData& _data, TaskContext& _context )
	{
		const bool modifyOriginal = getProperties().getModifyOriginal();

		std::string outputPath;

		if ( modifyOriginal )
		{
			outputPath = _context.getObject()->getPath().string();
		}
		else
		{
			auto& objectPath = _context.getObject()->getPath();

			const std::string directoryStr( getProperties().getOutputDirectory() );

			Utils::Path directoryPath =
					directoryStr.empty()
				?	objectPath.parent_path()
				:	Utils::Path( directoryStr );

			if ( !Filesystem::exists(directoryPath) )
				Filesystem::create_directory(directoryPath);

			outputPath =
				( directoryPath / objectPath.stem() ).string() +
				"_" +
				std::string( TaskType::getCodeName( getType() ) ) +
				"_" +
				std::string( TaskImplementationType::getCodeName( getImplementationType() ) )+
				"_" +
				boost::lexical_cast< std::string >( _context.getIteration() + 1) +
				objectPath.extension().string()
				;
		}

		cv::imwrite( outputPath, _data.m_target );
	}

}
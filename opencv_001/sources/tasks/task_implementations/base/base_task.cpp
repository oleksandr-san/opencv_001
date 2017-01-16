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

		ITaskResult::ObjectResultList& objectResults = result->takeObjectResults();

		for ( auto object : _objects )
			objectResults.push_back(
					ITaskResult::ObjectResult(
							object
						,	std::vector< ITaskResult::IterationResult >(
								static_cast< size_t >( getProperties().getRepeatsCount() )
							)
					)
				);

		TaskContext context;

		const int repeatsCount = getProperties().getRepeatsCount();
		for ( int i = 0; i < repeatsCount; ++i )
		{
			context.setIteration( i );

			const size_t objectsCount = _objects.size();
			for ( int j = 0; j < objectsCount; ++j )
			{
				context.setObject( _objects[ j ] );

				ITaskResult::IterationResult& iterationResult
					= objectResults[ j ].second[ i ];

				context.setCurrentIterationResult( iterationResult );

				ObjectData data;

				iterationResult.m_loadTime.first = Utils::TimePoint::clock::now();
				prepareObjectData( data, context );
				iterationResult.m_loadTime.second = Utils::TimePoint::clock::now();

				iterationResult.m_processTime.first = Utils::TimePoint::clock::now();
				runInternal( data );
				iterationResult.m_processTime.second = Utils::TimePoint::clock::now();

				iterationResult.m_saveTime.first = Utils::TimePoint::clock::now();
				saveObjectData( data, context );
				iterationResult.m_saveTime.second = Utils::TimePoint::clock::now();
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

			if ( !directoryStr.empty() && !Filesystem::exists(directoryPath) )
				Filesystem::create_directory(directoryPath);

			//static const std::string outputPathFormat = "%s/%s_%s_%s_%d%s";

			//auto formattedPath =
			//	boost::format( outputPathFormat )
			//		% directoryPath.string()
			//		% objectPath.stem().string()
			//		% TaskType::getCodeName( getType() )
			//		% TaskImplementationType::getCodeName( getImplementationType() )
			//		% ( _context.getIteration() + 1 )
			//		% objectPath.extension().string()
			//	;

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

		if ( auto iterationResult = _context.getIterationResul() )
			iterationResult->m_objectPath = outputPath;

		cv::imwrite( outputPath, _data.m_target );
	}

}
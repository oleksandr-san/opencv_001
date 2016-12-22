#include "ih/accessor/accessor.hpp"

#include "ih/utils/utils.hpp"

int main()
{
	Acessor accessor;

	auto taskManager = accessor.createTaskManager();
	auto objectsController = accessor.createObjectsController();

	auto task = taskManager->createTask( 
			Tasks::TaskType::Grayscale,
			Tasks::TaskImplementationType::Custom
		); 

	//auto task = taskManager->createTask( 
	//		Tasks::TaskType::BoxFilter,
	//		Tasks::TaskImplementationType::OpenCV
	//	); 

	Utils::Path filePath( "F:/wallpapers/3.jpg" );

	Objects::IProcessingObject::List objects;

	objects.push_back( objectsController->createProcessingObject( filePath ) );

	task->getProperties().setProperty( Tasks::TaskProperty::RepeatsCount, 1 );
	task->getProperties().setProperty( Tasks::TaskProperty::OutputDirectory, filePath.parent_path() );

	if ( task )
	{
		auto result = task->run( objects );
		auto time = result->getEndTime() - result->getStartTime();
		// integral duration: requires duration_cast
		auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>( time );
 
		// fractional duration: no duration_cast needed
		std::chrono::duration<double, std::milli > fp_ms = time;

		printf( "%lld ms, %f ms\n", int_ms.count(), fp_ms.count() );
	}
}
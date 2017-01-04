#include "qt_gui.h"

#include "resources.hpp"

#include <qfiledialog.h>
#include <QImage>
#include <QtWidgets>

qt_gui::qt_gui(QWidget *parent)
	:	QMainWindow(parent)
	,	m_isRunning( false )
{
    ui.setupUi(this);

	statusBarLabel = new QLabel(this);
	ui.statusBar->addPermanentWidget(statusBarLabel,0);

	updateTaskProperties();

	ui.label_8->setBackgroundRole(QPalette::Base);
	ui.label_8->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	ui.label_8->setScaledContents(true);
	ui.lineEdit->installEventFilter(this);

	ui.treeWidget->setColumnCount(7 );
	ui.treeWidget->setHeaderLabels(
			QStringList()
				<< "#"
				<< "Task Description"
				<< "Total Time"
				<< "Load Data Time"
				<< "Processing Time"
				<< "Average Processing Time"
				<< "Save Data Time"
		);
}


void qt_gui::updateTaskProperties()
{
	using namespace Tasks;

	for ( int i = Tasks::TaskType::First; i < Tasks::TaskType::Last; ++i )
	{
		ui.comboBox->insertItem( i, TaskType::getName( TaskType::fromInt( i ) ) );
	}

	for ( int i = TaskImplementationType::First; i < TaskImplementationType::Last; ++i )
	{
		ui.comboBox_2->insertItem( i, TaskImplementationType::getName( TaskImplementationType::fromInt( i ) ) );
	}

	ui.comboBox_3->insertItem(0, "False");
	ui.comboBox_3->insertItem(1, "True");

	ui.comboBox_4->insertItem(0, "False");
	ui.comboBox_4->insertItem(1, "True");
}


void qt_gui::updateImage( QString _path )
{
    QImageReader reader(_path);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(
			this,
			QGuiApplication::applicationDisplayName(),
			tr("Cannot load %1: %2")
			.arg(QDir::toNativeSeparators(_path),
			reader.errorString()));
        return;
    }

	currentImageFile = _path;
	ui.label_8->setPixmap(QPixmap::fromImage(newImage));
	ui.label_8->adjustSize();
}

void qt_gui::updateState( bool _isRunning )
{
	m_isRunning = _isRunning;

	//ui.pushButton->setEnabled( !m_isRunning );
	//ui.pushButton_2->setEnabled( !m_isRunning );
	//ui.pushButton_3->setEnabled( !m_isRunning );
	//ui.pushButton_4->setEnabled( !m_isRunning );

	//statusBarLabel->setText(  _isRunning ? "Running..." : "" );
}


bool qt_gui::eventFilter(QObject * object, QEvent * event)
{
    if(object == ui.lineEdit && event->type() == QEvent::MouseButtonPress)
	{
		auto directoryName = QFileDialog::getExistingDirectory(
				this,
				tr("Select folder")
			);
		if ( !directoryName.isEmpty() )
			ui.lineEdit->setText(directoryName);

        return false;
    }
    return false;
}


void qt_gui::processTaskResult( const Tasks::ITaskResult& _result )
{
	using namespace Tasks;

	auto convertTime =
		[]( float _time ) -> QString
		{
			return QString::number( _time, 'g', 3) + " s";
		}
	;

	const ITask& task = _result.getTask();
	const int repeatsCount = task.getProperties().getRepeatsCount();

	QTreeWidgetItem *topLevelItem = new QTreeWidgetItem(ui.treeWidget);

	struct FloatTimeResult
	{
		FloatTimeResult& operator += ( FloatTimeResult& _rhs )
		{
			total += _rhs.total;
			load += _rhs.load;
			process += _rhs.process;
			save += _rhs.save;
			return *this;
		}

		float total = 0, load = 0, process = 0, save = 0;
	};

	FloatTimeResult total;

	auto& objectResults = _result.getObjectResults();
	for ( auto& objectResult : objectResults )
	{
		QTreeWidgetItem *objectItem = new QTreeWidgetItem();

		FloatTimeResult object;

		assert( objectResult.second.size() == repeatsCount );
		for ( int i = 0; i < repeatsCount; ++i )
		{
			auto& iterationResult = objectResult.second[ i ];

			QTreeWidgetItem *iterationItem = new QTreeWidgetItem();

			FloatTimeResult iteration;

			iteration.load =
				std::chrono::duration_cast<std::chrono::duration<float>>(
					iterationResult.m_loadTime.second - iterationResult.m_loadTime.first
				).count();

			iteration.process =
				std::chrono::duration_cast<std::chrono::duration<float>>(
					iterationResult.m_processTime.second - iterationResult.m_processTime.first
				).count();

			iteration.save =
				std::chrono::duration_cast<std::chrono::duration<float>>(
					iterationResult.m_saveTime.second - iterationResult.m_saveTime.first
				).count();

			iteration.total = iteration.load + iteration.process + iteration.save;

			iterationItem->setText(1, QString( "Iteration %1" ).arg( i ) );
			iterationItem->setText(2, convertTime( iteration.total ) );
			iterationItem->setText(3, convertTime( iteration.load ) );
			iterationItem->setText(4, convertTime( iteration.process ) );
			iterationItem->setText(5, convertTime( iteration.process ) );
			iterationItem->setText(6, convertTime( iteration.save ) );

			objectItem->addChild( iterationItem );

			object += iteration;
		}

		total += object;

		objectItem->setText(1, QString( objectResult.first->getPath().string().c_str() ) );
		objectItem->setText(2, convertTime( object.total ) );
		objectItem->setText(3, convertTime( object.load ) );
		objectItem->setText(4, convertTime( object.process ) );
		objectItem->setText(5, convertTime( object.process / repeatsCount ) );
		objectItem->setText(6, convertTime( object.save ) );

		topLevelItem->addChild( objectItem );
	}

	QString taskDescription =
		QString("%1, %2, %3 times")
		.arg( TaskType::getName( task.getType() ) )
		.arg( TaskImplementationType::getName( task.getImplementationType() ) )
		.arg( repeatsCount );

	topLevelItem->setText(0, QString::number( ui.treeWidget->topLevelItemCount() ) );
	topLevelItem->setText(1, taskDescription);
	topLevelItem->setText(2, convertTime( total.total ) );
	topLevelItem->setText(3, convertTime( total.load ) );
	topLevelItem->setText(4, convertTime( total.process ) );
	topLevelItem->setText(5, convertTime( total.process / repeatsCount ) );
	topLevelItem->setText(6, convertTime( total.save ) );

	ui.treeWidget->addTopLevelItem(topLevelItem);

	updateState( false );
}


void qt_gui::on_pushButton_4_clicked()
{
	using namespace Tasks;

	try
	{
		TaskType::Enum type = TaskType::fromInt( ui.comboBox->currentIndex() );

		TaskImplementationType::Enum implType =
			TaskImplementationType::fromInt( ui.comboBox_2->currentIndex() );

		RunManager::ObjectList objects;

		const int itemsCount = ui.listWidget->count();
		for ( int i = 0; i < itemsCount; ++i )
		{
			objects.push_back( ui.listWidget->item( i )->text().toStdString() );
		}

		if ( !objects.empty() )
		{
			updateState( true );

			auto taskResult = runManager.runTask(
					objects,
					type,
					implType,
					ui.spinBox->value(),
					ui.spinBox_2->value(),
					ui.doubleSpinBox->value(),
					ui.lineEdit->text().toStdString(),
					ui.comboBox_3->currentIndex() == 1,
					ui.comboBox_4->currentIndex() == 1
				);

			if ( taskResult )
				processTaskResult( *taskResult );

			updateState( false );
		}
	}
	catch( std::exception & _e )
	{
        QMessageBox::information(
			this,
			QGuiApplication::applicationDisplayName(),
			_e.what()
		);
	}
}


void qt_gui::on_pushButton_2_clicked()
{
	auto fileNames = QFileDialog::getOpenFileNames(
			this,
			tr("Open Image"),
			"",
			tr(Resources::OpenFileDialogImageFilter)
		);

	for ( auto fileName : fileNames )
		if ( !fileName.isEmpty() )
			ui.listWidget->addItem(fileName);
}


void qt_gui::on_pushButton_3_clicked()
{
    auto imageItemList = ui.listWidget->selectedItems();
	for ( auto imageItem : imageItemList )
	{
		if ( !currentImageFile.compare( imageItem->text() ) )
		{
			currentImageFile.clear();
			ui.label_8->setPixmap(QPixmap());
		}

		auto item2Delete =
			ui.listWidget->takeItem(
				ui.listWidget->row( imageItem )
			);

		delete item2Delete;
	}
}


void qt_gui::on_pushButton_clicked()
{
	auto imageItemList = ui.listWidget->selectedItems();
	if ( imageItemList.size() == 1 )
	{
		updateImage( imageItemList.first()->text() );
	}
}


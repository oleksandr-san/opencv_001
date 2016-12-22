#include "qt_gui.h"

#include "resources.hpp"

#include "opencv_001/ih/tasks/task_kind.hpp"
#include "opencv_001/ih/tasks/task_implementation_type.hpp"

#include <qfiledialog.h>
#include <QImage>
#include <QtWidgets>

qt_gui::qt_gui(QWidget *parent)
	: QMainWindow(parent)
{
    ui.setupUi(this);

	updateTaskProperties();
}

void qt_gui::updateTaskProperties()
{
	for ( int i = Tasks::TaskType::First; i < Tasks::TaskType::Last; ++i )
	{
		ui.comboBox->insertItem(
				i
			,	Tasks::TaskType::getName(
					static_cast< Tasks::TaskType::Enum >( i )
				)
		);
	}

	for (
		int i = Tasks::TaskImplementationType::First;
		i < Tasks::TaskImplementationType::Last;
		++i
	)
	{
		ui.comboBox_2->insertItem(
				i
			,	Tasks::TaskImplementationType::getName(
					static_cast< Tasks::TaskImplementationType::Enum >( i )
				)
		);
	}
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

	auto oldSize = ui.label->size();
	ui.label->setPixmap(QPixmap::fromImage(newImage));
	//ui.label->resize( oldSize );

	ui.label->setBackgroundRole(QPalette::Base);
    ui.label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui.label->setScaledContents(true);
}


void qt_gui::on_comboBox_2_currentIndexChanged(int index)
{

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


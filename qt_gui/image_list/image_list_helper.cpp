#include <QtWidgets>
#include "image_list_helper.hpp"

void ImageListHelper::init(QTableWidget * table)
{
	table_ = table;

	initTable();
}

void ImageListHelper::addImageItem(const QString & _path)
{
	//table_->set
}

QStringList ImageListHelper::getSelectedItems()
{
	return QStringList();
}

void ImageListHelper::initTable()
{
	table_->setColumnCount( 2 );

	table_->setHorizontalHeaderLabels(
			QStringList() << "File Path" << "Resolution"
		);

	table_->setRowCount( 2 );

	table_->setItem(1, 0, new QTableWidgetItem("LUL"));
}
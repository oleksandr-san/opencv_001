#ifndef __IMAGE_LIST_HELPER_HPP__
#define __IMAGE_LIST_HELPER_HPP__

#include <qtablewidget.h>

class ImageListHelper
{

public:
	void init( QListWidget* widget);

	void addImageItem( const QString& _path );

	QStringList getSelectedItems();

private:

	void initTable();

	QListWidget* widget_;

};

#endif
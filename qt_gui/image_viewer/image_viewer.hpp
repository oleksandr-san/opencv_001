#ifndef __IMAGEVIEWER_HPP__
#define __IMAGEVIEWER_HPP__

#include <QMainWindow>
#include <QImage>
#include <qevent.h>

class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;

class ImageViewer: public QWidget
{
	Q_OBJECT

public:
	ImageViewer();

	void initViewer(QScrollArea* _scrollArea);

	bool loadFile(const QString &);

	bool hasImage( const QString& _path);

	void clear();

	bool eventFilter(QObject* /*obj*/, QEvent* evt)
	{
		if (evt->type() == QEvent::Wheel)
		{
			// ignore the event (this effectively 
			// makes it "skip" one object)
			evt->ignore();
		}
		// return false to continue event propagation
		// for all events
		return false;
	}

protected:
	void wheelEvent(QWheelEvent* event);

private slots:
	void zoomIn();
	void zoomOut();
	void normalSize();

private:

	void setImage(const QImage &newImage);
	void scaleImage(double factor);
	void adjustScrollBar(QScrollBar *scrollBar, double factor);

	QString imageFile;
	QImage image;
	QLabel *imageLabel;
	QScrollArea *scrollArea;
	double scaleFactor;
};

#endif
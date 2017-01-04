#include <QtWidgets>

#include "image_viewer.hpp"

ImageViewer::ImageViewer()
	: imageLabel(nullptr)
	, scrollArea(nullptr)
	, scaleFactor(1)
{
}


void ImageViewer::initViewer(QScrollArea* _scrollArea)
{
	imageLabel = new QLabel();

	imageLabel->setBackgroundRole(QPalette::Base);
	imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	imageLabel->setScaledContents(true);

	QHBoxLayout *layout = new QHBoxLayout();
	layout->addWidget(imageLabel);
	setLayout(layout);

	scrollArea = _scrollArea;

	scrollArea->setBackgroundRole(QPalette::Light);
	scrollArea->setWidget(this);
	scrollArea->viewport()->installEventFilter(this);
}

void ImageViewer::wheelEvent(QWheelEvent* event)
{
  //  if (event->modifiers().testFlag(Qt::ControlModifier)) 
  //  {
		//if ( event->delta() > 0 )
		//	zoomIn();
		//else 
		//	zoomOut();
  //  }

	event->accept();
}

bool ImageViewer::loadFile(const QString &fileName)
{
	QImageReader reader(fileName);
	reader.setAutoTransform(true);
	const QImage newImage = reader.read();
	if (newImage.isNull()) {
		QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
			tr("Cannot load %1: %2")
			.arg(QDir::toNativeSeparators(fileName), reader.errorString()));
		return false;
	}

	imageFile = fileName;

	setImage(newImage);

	setWindowFilePath(fileName);

	return true;
}

bool ImageViewer::hasImage(const QString & _path)
{
	return imageLabel->pixmap() && !imageFile.compare( _path );
}

void ImageViewer::clear()
{
	imageLabel->setPixmap(QPixmap());
	imageFile.clear();
}

void ImageViewer::setImage(const QImage &newImage)
{
	image = newImage;
	imageLabel->setPixmap(QPixmap::fromImage(image));
	scaleFactor = 1.0;

	scrollArea->setVisible(true);
	imageLabel->adjustSize();
}

void ImageViewer::zoomIn()
{
	scaleImage(1.25);
}

void ImageViewer::zoomOut()
{
	scaleImage(0.8);
}

void ImageViewer::normalSize()
{
	imageLabel->adjustSize();
	scaleFactor = 1.0;
}

void ImageViewer::scaleImage(double factor)
{
	if ( !imageLabel->pixmap() )
		return;

	scaleFactor *= factor;
	imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

	adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
	adjustScrollBar(scrollArea->verticalScrollBar(), factor);
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
	scrollBar->setValue(int(factor * scrollBar->value()
		+ ((factor - 1) * scrollBar->pageStep() / 2)));
}
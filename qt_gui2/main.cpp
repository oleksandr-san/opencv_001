#define QT_NO_PRINTER

#include <QApplication>
#include <QCommandLineParser>

#include "qt_gui2.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(ImageViewer::tr("Image Viewer"));
	ImageViewer imageViewer;

    imageViewer.show();
    return app.exec();
}
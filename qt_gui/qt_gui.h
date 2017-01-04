#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qt_gui.h"
#include "image_viewer/image_viewer.hpp"
#include "run_manager/run_manager.hpp"

class qt_gui
	: public QMainWindow
{
    Q_OBJECT

public:
    qt_gui(QWidget *parent = Q_NULLPTR);

	bool eventFilter(QObject* object, QEvent* event);

private slots:
    void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::qt_guiClass ui;

	QLabel* statusBarLabel;

	QString currentImageFile;

	RunManager runManager;

	bool m_isRunning;

private:

	void updateTaskProperties();
	void updateImage( QString _path );
	void updateState( bool _isRunning );
	void processTaskResult( const Tasks::ITaskResult& _result );
};

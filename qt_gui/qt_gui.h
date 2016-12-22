#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qt_gui.h"

class qt_gui : public QMainWindow
{
    Q_OBJECT

public:
    qt_gui(QWidget *parent = Q_NULLPTR);

private slots:
    void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_clicked();

private:
    Ui::qt_guiClass ui;
	void on_comboBox_2_currentIndexChanged(int index);

private:

	void updateTaskProperties();
	void updateImage( QString _path );
};

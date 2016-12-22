/********************************************************************************
** Form generated from reading UI file 'qt_gui2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_GUI2_H
#define UI_QT_GUI2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_gui2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_gui2Class)
    {
        if (qt_gui2Class->objectName().isEmpty())
            qt_gui2Class->setObjectName(QStringLiteral("qt_gui2Class"));
        qt_gui2Class->resize(600, 400);
        menuBar = new QMenuBar(qt_gui2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        qt_gui2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_gui2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qt_gui2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(qt_gui2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qt_gui2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qt_gui2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qt_gui2Class->setStatusBar(statusBar);

        retranslateUi(qt_gui2Class);

        QMetaObject::connectSlotsByName(qt_gui2Class);
    } // setupUi

    void retranslateUi(QMainWindow *qt_gui2Class)
    {
        qt_gui2Class->setWindowTitle(QApplication::translate("qt_gui2Class", "qt_gui2", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_gui2Class: public Ui_qt_gui2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_GUI2_H

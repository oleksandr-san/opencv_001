/********************************************************************************
** Form generated from reading UI file 'qt_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_GUI_H
#define UI_QT_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_guiClass
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionClose;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter_2;
    QWidget *verticalWidget_3;
    QGridLayout *gridLayout_7;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QGridLayout *gridLayout_4;
    QFrame *frame;
    QGridLayout *gridLayout_10;
    QLabel *label_8;
    QWidget *verticalWidget_2;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_9;
    QListWidget *listWidget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QLabel *label_7;
    QSpinBox *spinBox;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLabel *label;
    QComboBox *comboBox_3;
    QLabel *label_9;
    QComboBox *comboBox_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QTreeWidget *treeWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_guiClass)
    {
        if (qt_guiClass->objectName().isEmpty())
            qt_guiClass->setObjectName(QStringLiteral("qt_guiClass"));
        qt_guiClass->resize(985, 898);
        actionOpen = new QAction(qt_guiClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(qt_guiClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionClose = new QAction(qt_guiClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralWidget = new QWidget(qt_guiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        verticalWidget_3 = new QWidget(splitter_2);
        verticalWidget_3->setObjectName(QStringLiteral("verticalWidget_3"));
        gridLayout_7 = new QGridLayout(verticalWidget_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        splitter = new QSplitter(verticalWidget_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        gridLayout_4 = new QGridLayout(verticalLayoutWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(verticalLayoutWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_8, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame, 0, 2, 1, 1);

        splitter->addWidget(verticalLayoutWidget);
        verticalWidget_2 = new QWidget(splitter);
        verticalWidget_2->setObjectName(QStringLiteral("verticalWidget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalWidget_2->sizePolicy().hasHeightForWidth());
        verticalWidget_2->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(verticalWidget_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        splitter_3 = new QSplitter(verticalWidget_2);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_9 = new QVBoxLayout(layoutWidget);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_9 = new QGridLayout(groupBox_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        listWidget = new QListWidget(groupBox_4);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout_9->addWidget(listWidget, 1, 0, 1, 1);

        widget_2 = new QWidget(groupBox_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(true);

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        gridLayout_9->addWidget(widget_2, 2, 0, 1, 1);


        verticalLayout_9->addWidget(groupBox_4);

        splitter_3->addWidget(layoutWidget);
        groupBox = new QGroupBox(splitter_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMaximumSize(QSize(16777215, 16777215));
        comboBox->setEditable(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        sizePolicy.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy);
        comboBox_2->setMaximumSize(QSize(16777215, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_2);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);
        spinBox->setMinimum(1);
        spinBox->setMaximum(999999);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_3);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        sizePolicy1.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy1);
        spinBox_2->setLayoutDirection(Qt::LeftToRight);
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(999);
        spinBox_2->setSingleStep(2);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBox_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setValue(1);

        formLayout->setWidget(6, QFormLayout::FieldRole, doubleSpinBox);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_6);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        lineEdit->setReadOnly(true);

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEdit);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        formLayout->setWidget(9, QFormLayout::FieldRole, comboBox_3);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_9);

        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        formLayout->setWidget(10, QFormLayout::FieldRole, comboBox_4);

        splitter_3->addWidget(groupBox);

        verticalLayout_3->addWidget(splitter_3);

        groupBox_3 = new QGroupBox(verticalWidget_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_8 = new QGridLayout(groupBox_3);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_8->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_8->addWidget(pushButton_6, 1, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_3);


        gridLayout_5->addLayout(verticalLayout_3, 0, 0, 1, 1);

        splitter->addWidget(verticalWidget_2);

        gridLayout_7->addWidget(splitter, 0, 0, 1, 1);

        splitter_2->addWidget(verticalWidget_3);
        widget = new QWidget(splitter_2);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        treeWidget = new QTreeWidget(groupBox_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(1, QStringLiteral("2"));
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setColumnCount(2);

        gridLayout_6->addWidget(treeWidget, 0, 0, 2, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        splitter_2->addWidget(widget);

        gridLayout_2->addWidget(splitter_2, 0, 0, 1, 1);

        qt_guiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qt_guiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qt_guiClass->setStatusBar(statusBar);

        retranslateUi(qt_guiClass);

        QMetaObject::connectSlotsByName(qt_guiClass);
    } // setupUi

    void retranslateUi(QMainWindow *qt_guiClass)
    {
        qt_guiClass->setWindowTitle(QApplication::translate("qt_guiClass", "qt_gui", 0));
        actionOpen->setText(QApplication::translate("qt_guiClass", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("qt_guiClass", "Ctrl+O", 0));
        actionExit->setText(QApplication::translate("qt_guiClass", "Exit", 0));
        actionClose->setText(QApplication::translate("qt_guiClass", "Close", 0));
        label_8->setText(QString());
        groupBox_4->setTitle(QApplication::translate("qt_guiClass", "Image List", 0));
        pushButton_2->setText(QApplication::translate("qt_guiClass", "Add", 0));
        pushButton_3->setText(QApplication::translate("qt_guiClass", "Remove", 0));
        pushButton->setText(QApplication::translate("qt_guiClass", "Show", 0));
        groupBox->setTitle(QApplication::translate("qt_guiClass", "Task Properties", 0));
        label_2->setText(QApplication::translate("qt_guiClass", "Task Type", 0));
        label_5->setText(QApplication::translate("qt_guiClass", "Implementation Type", 0));
        label_7->setText(QApplication::translate("qt_guiClass", "Repeats Count", 0));
        label_3->setText(QApplication::translate("qt_guiClass", "Blurring Kernel Size", 0));
        label_4->setText(QApplication::translate("qt_guiClass", "Sigma X", 0));
        label_6->setText(QApplication::translate("qt_guiClass", "Output Directory", 0));
        label->setText(QApplication::translate("qt_guiClass", "Modify Original", 0));
        label_9->setText(QApplication::translate("qt_guiClass", "Optimize Block Processing", 0));
        groupBox_3->setTitle(QApplication::translate("qt_guiClass", "Processing", 0));
        pushButton_4->setText(QApplication::translate("qt_guiClass", "Run Task", 0));
        pushButton_6->setText(QApplication::translate("qt_guiClass", "Clear Results", 0));
        groupBox_2->setTitle(QApplication::translate("qt_guiClass", "Results", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_guiClass: public Ui_qt_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_GUI_H

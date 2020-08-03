/********************************************************************************
** Form generated from reading UI file 'antikc.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANTIKC_H
#define UI_ANTIKC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_antikcClass
{
public:
    QAction *actionPreferences;
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *version_label;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;

    void setupUi(QMainWindow *antikcClass)
    {
        if (antikcClass->objectName().isEmpty())
            antikcClass->setObjectName(QString::fromUtf8("antikcClass"));
        antikcClass->resize(464, 672);
        QFont font;
        font.setFamily(QString::fromUtf8("Source Code Pro"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        antikcClass->setFont(font);
        antikcClass->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	font: 10pt \"Source Code Pro\";\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QMainWindow\n"
"{\n"
"	background-color: rgb(47, 49, 54);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QMenuBar\n"
"{\n"
"	border-radius: 4px;\n"
"	background-color: #2F3136;\n"
"	color: #F9F3ED;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"	border-radius: 4px;\n"
"	background-color: #5C626C;\n"
"	color: #F9F3ED;\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"	border-radius: 4px;\n"
"	background-color: #51545E;\n"
"	color: #F9F3ED;\n"
"}\n"
"\n"
"QMenu::item\n"
"{\n"
"	border-radius: 4px;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{	\n"
"	border-radius: 4px;\n"
"	background-color: #5C626C;\n"
"	color: #F9F3ED;\n"
"}\n"
"\n"
""));
        actionPreferences = new QAction(antikcClass);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionQuit = new QAction(antikcClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(antikcClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("\n"
"QLabel\n"
"{\n"
"	color: #DCDDD9;\n"
"}\n"
"\n"
"QHeaderView\n"
"{\n"
"	border: 0px;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{	\n"
"	border-radius: 0px;\n"
"	padding-left: 3px;\n"
"	color: #DCDDD9;\n"
"	background-color: #393C42;\n"
"}\n"
"\n"
"QTableView\n"
"{\n"
"	border-radius: 4px;\n"
"	background-color: #2F3136;\n"
"	gridline-color: #2F3136;\n"
"	outline: 0;\n"
"}\n"
"\n"
"QTableView::item\n"
"{\n"
"	color: #DCDDD9;\n"
"	border: 0px;\n"
"}\n"
"\n"
"QTableView::item::selected\n"
"{\n"
"	background-color:#40444B;\n"
"}\n"
"\n"
"QScrollBar:vertical {              \n"
"        border: 1px solid #999999;\n"
"        background:white;\n"
"        width:10px;    \n"
"        margin: 0px 0px 0px 0px;\n"
"    }\n"
"    QScrollBar::handle:vertical {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop: 0 rgb(118, 134, 224), stop: 0.5 rgb(118, 134, 224), stop:1 rgb(118, 134, 224));\n"
"        min-height: 0px;\n"
"    }\n"
"    QScrollBar::add-line:vertical {\n"
"        background: "
                        "qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop: 0 rgb(118, 134, 224), stop: 0.5 rgb(118, 134, 224),  stop:1 rgb(118, 134, 224));\n"
"        height: 0px;\n"
"        subcontrol-position: bottom;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::sub-line:vertical {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop: 0  rgb(118, 134, 224), stop: 0.5 rgb(118, 134, 224),  stop:1 rgb(118, 134, 224));\n"
"        height: 0 px;\n"
"        subcontrol-position: top;\n"
"        subcontrol-origin: margin;\n"
"    }"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(50, 16777215));
        lineEdit->setStyleSheet(QString::fromUtf8("color: #DFD9D4;\n"
"background-color: #40444B;\n"
"border: 0px;\n"
"border-radius: 4px;"));

        gridLayout->addWidget(lineEdit, 1, 3, 1, 1);

        version_label = new QLabel(centralWidget);
        version_label->setObjectName(QString::fromUtf8("version_label"));
        version_label->setStyleSheet(QString::fromUtf8("color: rgb(76, 76, 76);"));

        gridLayout->addWidget(version_label, 3, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label, 1, 4, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(tableView, 2, 0, 1, 5);

        antikcClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(antikcClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 464, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        antikcClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionQuit);
        menuSettings->addAction(actionPreferences);

        retranslateUi(antikcClass);

        QMetaObject::connectSlotsByName(antikcClass);
    } // setupUi

    void retranslateUi(QMainWindow *antikcClass)
    {
        antikcClass->setWindowTitle(QApplication::translate("antikcClass", "antikc", nullptr));
        actionPreferences->setText(QApplication::translate("antikcClass", "Preferences", nullptr));
        actionQuit->setText(QApplication::translate("antikcClass", "Quit", nullptr));
        lineEdit->setText(QApplication::translate("antikcClass", "85", nullptr));
        version_label->setText(QString());
        label->setText(QApplication::translate("antikcClass", "ms", nullptr));
        menuFile->setTitle(QApplication::translate("antikcClass", "File", nullptr));
        menuSettings->setTitle(QApplication::translate("antikcClass", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class antikcClass: public Ui_antikcClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANTIKC_H

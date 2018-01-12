/********************************************************************************
** Form generated from reading UI file 'antikc.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANTIKC_H
#define UI_ANTIKC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
    QAction *actionQuit;
    QAction *actionQuit_2;
    QAction *actionQuit_3;
    QAction *actionPreferences;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *version_label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;

    void setupUi(QMainWindow *antikcClass)
    {
        if (antikcClass->objectName().isEmpty())
            antikcClass->setObjectName(QStringLiteral("antikcClass"));
        antikcClass->resize(600, 400);
        antikcClass->setStyleSheet(QLatin1String("QMainWindow\n"
"{\n"
"	background-color: rgb(202, 225, 255);\n"
"}\n"
"\n"
"QMenuBar\n"
"{\n"
"	\n"
"	background-color: rgb(128, 194, 255);\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"	background-color: rgb(202, 225, 255);\n"
"}\n"
"\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"	background-color: rgb(221, 236, 255);\n"
"	color: rgb(36, 36, 36);\n"
" }\n"
""));
        actionQuit = new QAction(antikcClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionQuit_2 = new QAction(antikcClass);
        actionQuit_2->setObjectName(QStringLiteral("actionQuit_2"));
        actionQuit_3 = new QAction(antikcClass);
        actionQuit_3->setObjectName(QStringLiteral("actionQuit_3"));
        actionPreferences = new QAction(antikcClass);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        centralWidget = new QWidget(antikcClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("\n"
"QLabel\n"
"{\n"
"	color: rgb(36, 36, 36);\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{	\n"
"	color: rgb(45, 45, 45);\n"
"}\n"
"\n"
"QTableView\n"
"{\n"
"	gridline-color: rgb(106, 106, 106);\n"
"	outline: 0;\n"
"}\n"
"\n"
"QTableView::item\n"
"{\n"
"	border: 0px;\n"
"}\n"
"\n"
"QTableView::item::selected\n"
"{\n"
"	background-color: rgb(104, 180, 255);\n"
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
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop: 0 rgb(118, 134, 224), stop: 0.5 rgb(118, 134, 224),  stop:1 rgb(118, 134, 224));\n"
"        height: 0px;\n"
"   "
                        "     subcontrol-position: bottom;\n"
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
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(tableView, 2, 0, 1, 4);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(50, 16777215));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit, 1, 3, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("Noto Mono"));
        font.setPointSize(14);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        version_label = new QLabel(centralWidget);
        version_label->setObjectName(QStringLiteral("version_label"));
        version_label->setStyleSheet(QStringLiteral("color: rgb(76, 76, 76);"));

        gridLayout->addWidget(version_label, 3, 3, 1, 1);

        antikcClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(antikcClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        antikcClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionQuit_3);
        menuSettings->addAction(actionPreferences);

        retranslateUi(antikcClass);

        QMetaObject::connectSlotsByName(antikcClass);
    } // setupUi

    void retranslateUi(QMainWindow *antikcClass)
    {
        antikcClass->setWindowTitle(QApplication::translate("antikcClass", "antikc", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("antikcClass", "Quit", Q_NULLPTR));
        actionQuit_2->setText(QApplication::translate("antikcClass", "Quit", Q_NULLPTR));
        actionQuit_3->setText(QApplication::translate("antikcClass", "Quit", Q_NULLPTR));
        actionPreferences->setText(QApplication::translate("antikcClass", "Preferences", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("antikcClass", "85", Q_NULLPTR));
        label->setText(QApplication::translate("antikcClass", "ms", Q_NULLPTR));
        label_2->setText(QApplication::translate("antikcClass", "antikc", Q_NULLPTR));
        version_label->setText(QString());
        menuFile->setTitle(QApplication::translate("antikcClass", "File", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("antikcClass", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class antikcClass: public Ui_antikcClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANTIKC_H

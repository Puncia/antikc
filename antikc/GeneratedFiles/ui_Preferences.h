/********************************************************************************
** Form generated from reading UI file 'Preferences.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Preferences
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_button;
    QSpacerItem *verticalSpacer;
    QCheckBox *autostartCheckBox;

    void setupUi(QWidget *Preferences)
    {
        if (Preferences->objectName().isEmpty())
            Preferences->setObjectName(QString::fromUtf8("Preferences"));
        Preferences->resize(400, 150);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Preferences->sizePolicy().hasHeightForWidth());
        Preferences->setSizePolicy(sizePolicy);
        Preferences->setMinimumSize(QSize(400, 150));
        Preferences->setMaximumSize(QSize(400, 450));
        gridLayout = new QGridLayout(Preferences);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        ok_button = new QPushButton(Preferences);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));

        gridLayout->addWidget(ok_button, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        autostartCheckBox = new QCheckBox(Preferences);
        autostartCheckBox->setObjectName(QString::fromUtf8("autostartCheckBox"));

        gridLayout->addWidget(autostartCheckBox, 0, 0, 1, 1);


        retranslateUi(Preferences);

        QMetaObject::connectSlotsByName(Preferences);
    } // setupUi

    void retranslateUi(QWidget *Preferences)
    {
        Preferences->setWindowTitle(QApplication::translate("Preferences", "Preferences", nullptr));
        ok_button->setText(QApplication::translate("Preferences", "OK", nullptr));
        autostartCheckBox->setText(QApplication::translate("Preferences", "Start with Windows", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Preferences: public Ui_Preferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H

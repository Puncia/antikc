#pragma once

#include <QDialog>
#include "ui_Preferences.h"
#include <QFile>
#include <QFileInfo>
#include "shobjidl.h"

class Preferences : public QDialog
{
	Q_OBJECT

public:
	Preferences(QDialog *parent = Q_NULLPTR);
	~Preferences();


private:
	Ui::Preferences ui;
	bool autostart = false;
	QString lnkpth = "C:\\Users\\" + QString(getenv("USERNAME")) + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\antikc.lnk";

public slots:
	void ok_clicked();
	void autostart_box_toggled(bool checked);
};

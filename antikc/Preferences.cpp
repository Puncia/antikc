#include "Preferences.h"

Preferences::Preferences(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setFixedSize(400, 150);

	QObject::connect(ui.ok_button, SIGNAL(clicked()), this, SLOT(ok_clicked()));
	QObject::connect(ui.autostartCheckBox, SIGNAL(toggled(bool)), this, SLOT(autostart_box_toggled(bool)));

	if (QFile::exists(lnkpth))
		ui.autostartCheckBox->setChecked(autostart = true);
}

Preferences::~Preferences()
{
}

void Preferences::ok_clicked()
{
	close();
}

void Preferences::autostart_box_toggled(bool checked)
{
	autostart = checked;
	QFile f, lnk;	

	if (checked)
	{
		f.setFileName(QFileInfo(QCoreApplication::applicationFilePath()).filePath());
		f.link("antikc.lnk");
		lnk.setFileName("antikc.lnk");
		lnk.rename(lnkpth);
	}
	else
	{
		lnk.setFileName(lnkpth);
		lnk.remove();
	}
}
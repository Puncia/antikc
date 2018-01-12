#pragma once

#include "resource.h"

#include <QtWidgets/QMainWindow>
#include "ui_antikc.h"
#include <iostream>
#include <memory>
#include <Windows.h>
#include <QCoreApplication>
#include <QStandardItemModel>

class antikc : public QMainWindow
{
	Q_OBJECT

public:
	antikc(QWidget *parent = Q_NULLPTR);
	~antikc();
	void appendLog(QString msg);
	static void updateView();

public slots:
	void update_ms_threshold(const QString &ms);

private:
	Ui::antikcClass ui;
};

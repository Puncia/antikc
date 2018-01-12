#pragma once

#include "resource.h"

#include <QtWidgets/QMainWindow>
#include "ui_antikc.h"
#include <iostream>
#include <memory>
#include <Windows.h>
#include <QCoreApplication>
#include <QStandardItemModel>

#define ALLOW_INPUT 0
#define BLOCK_INPUT 1

class antikc : public QMainWindow
{
	Q_OBJECT

public:
	antikc(QWidget *parent = Q_NULLPTR);
	~antikc();

	//we register each chatter timing for every key
	struct _chatters
	{
		uint count = 0;
		std::list<double> timings_converted;
	};

	//main keystat struct
	struct _keystat
	{
		uint code; //vk
		double timing = 0.0;
		uint threshold = 0;
		_chatters chatters;
		bool down = false;
	};
	static std::list<_keystat> keystats;

	static QStandardItemModel *iModel;

	static void updateView();

public slots:
	void update_ms_threshold(const QString &ms);

private:
	Ui::antikcClass ui;
	HANDLE h_handle;
	INPUT ip;

};

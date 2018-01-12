#include "antikc.h"

HANDLE hClass = NULL;
HANDLE h_handle;
QStandardItemModel *iModel;
INPUT ip;

struct _chatters
{
	uint count = 0;
	std::list<double> timings_converted;
};

struct _keystat
{
	uint code;
	double timing = 0.0;
	uint threshold = 0;
	_chatters chatters;
	bool down = false;
};
std::list<_keystat> keystats;

static LRESULT CALLBACK h_callback(int nCode, WPARAM wParam, LPARAM lParam);
_keystat getNewKeystat(DWORD vkCode);
bool sort_compare(_keystat &first, _keystat &second);


uint global_threshold = 85;
double frequency = 0.0;

antikc::antikc(QWidget *parent)
	: QMainWindow(parent)
{
	LARGE_INTEGER boop;

	ui.setupUi(this);
	ui.centralWidget->setObjectName("centralWidget");
	hClass = this;
	iModel = new QStandardItemModel(0, 4);
	
	QStringList headers;
	headers << "Key" << "Timing" << "Threshold" << "# Chatters";

	iModel->setHorizontalHeaderLabels(headers);
	ui.tableView->verticalHeader()->setVisible(false);
	ui.tableView->horizontalHeader()->setStretchLastSection(false);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
	ui.tableView->horizontalHeader()->setHighlightSections(false);
	ui.tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	//ui.tableView->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	ui.tableView->setModel(iModel);
	ui.tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	ui.tableView->setColumnWidth(0, 20);

	int v[4] = { RC_VERSION };

	ui.version_label->setText("v" +
		QString::number(v[0]) + "." +
		QString::number(v[1]) + "." +
		QString::number(v[2]) + "." +
		QString::number(v[3]));

	QueryPerformanceFrequency(&boop);
	frequency = double(boop.QuadPart) / 1000.0;

	QObject::connect(ui.lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(update_ms_threshold(const QString &)));

	ui.lineEdit->setMaxLength(4);
	QRegExpValidator *rxv = new QRegExpValidator(QRegExp("\\d*"), this);
	ui.lineEdit->setValidator(rxv);

	h_handle = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)h_callback, 0, 0);
}

void antikc::update_ms_threshold(const QString &ms)
{
	global_threshold = ui.lineEdit->text().toInt();
}

LRESULT CALLBACK h_callback(int nCode, WPARAM wParam, LPARAM lParam)
{
	LARGE_INTEGER boop; //used to just store current timing temporarily

	if (nCode < 0)
		return CallNextHookEx(NULL, nCode, wParam, lParam);
	else
	{
		KBDLLHOOKSTRUCT *det = (KBDLLHOOKSTRUCT*) lParam;
		if (nCode == HC_ACTION && ((wParam == WM_KEYDOWN) || wParam == WM_SYSKEYDOWN))
		{
			//there's always a first time
			if (keystats.size() == 0)
			{
				keystats.push_back(getNewKeystat(det->vkCode));
				antikc::updateView();
				return 0;
			}

			//lookup this key in our list
			for (auto i = keystats.begin(), end = keystats.end(); i != end; i++)
			{
				//we found our key in our list - meaning it has already been pressed before (not near past)
				if ((i->code == det->vkCode) && !i->down)
				{
					QueryPerformanceCounter(&boop);
					i->down = true;

					//is it chattering?
					if (double(boop.QuadPart - i->timing) / frequency < i->threshold)
					{
						i->chatters.count++;
						i->chatters.timings_converted.push_back((boop.QuadPart - i->timing) / frequency);
						
						antikc::updateView();

						i->timing = boop.QuadPart;
						return 1;
					}
					else
					{
						i->timing = boop.QuadPart;
						return 0;
					}
				}
				else if(i->code == det->vkCode)
				{
					return 0;
				}
			}

			//we don't find this key in the list so we add it
			keystats.push_back(getNewKeystat(det->vkCode));
			antikc::updateView();
			
		}
		else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
		{
			//lookup this key in our list
			for (auto i = keystats.begin(), end = keystats.end(); i != end; i++)
			{
				//we found our key in our list - meaning it has already been pressed
				if (i->code == det->vkCode)
				{
					i->down = false;
				}
			}
		}
		return CallNextHookEx(NULL, nCode, wParam, lParam);
	}
}

bool sort_compare(_keystat &first, _keystat &second)
{
	if (first.chatters.count > second.chatters.count)
		return true;
	return false;
}

_keystat getNewKeystat(DWORD vkCode)
{
	_keystat paski;
	LARGE_INTEGER boop;
	QueryPerformanceCounter(&boop);
	paski.timing = boop.QuadPart;
	paski.threshold = global_threshold;
	paski.code = vkCode;
	paski.chatters.count = 0;

	return paski;
}

void antikc::updateView()
{
	int i = 0;
	keystats.sort(sort_compare);

	for each (auto keystat in keystats)
	{
		UINT kcode = MapVirtualKey(keystat.code, 2);
		if (iModel->rowCount() >= i + 1)
		{
			iModel->item(i, 0)->setData(QString(kcode) + " (" + QString::number(keystat.code) + ")", Qt::DisplayRole);
			iModel->item(i, 1)->setData((LONGLONG)keystat.timing, Qt::DisplayRole);
			iModel->item(i, 2)->setData(keystat.threshold, Qt::DisplayRole);
			iModel->item(i++, 3)->setData(keystat.chatters.count, Qt::DisplayRole);
		}
		else
		{
			QList<QStandardItem *> itemlist;
			itemlist << new QStandardItem(QString(QString(kcode)) + " (" + QString::number(keystat.code) + ")")
				<< new QStandardItem(QString::number((LONGLONG)keystat.timing))
				<< new QStandardItem(QString::number(keystat.threshold))
				<< new QStandardItem(QString::number(keystat.chatters.count));

			iModel->appendRow(itemlist);
		}
	}
}

antikc::~antikc()
{
	UnhookWindowsHookEx((HHOOK)h_handle);
	delete iModel;
}
#include "antikc.h"

std::list<antikc::_keystat> antikc::keystats;
QStandardItemModel *antikc::iModel;

//need to save an handle to antikc class for WinAPI callback
HANDLE hClass = NULL;

//WinAPI callback
static LRESULT CALLBACK h_callback(int nCode, WPARAM wParam, LPARAM lParam);

//gets called everytime a new key is registered
antikc::_keystat getNewKeystat(DWORD vkCode);

//predicate to sort our keystats list
bool sort_compare(antikc::_keystat &first, antikc::_keystat &second);

//global threshold, updated everytime the dedicated textbox's value gets changed
uint global_threshold = 85;

//CPU frequency
double frequency = 0.0;

antikc::antikc(QWidget *parent)
	: QMainWindow(parent)
{
	LARGE_INTEGER boop;

	QueryPerformanceFrequency(&boop);
	frequency = double(boop.QuadPart) / 1000.0;

	ui.setupUi(this);
	ui.centralWidget->setObjectName("centralWidget");
	hClass = this;
	iModel = new QStandardItemModel(0, 4);
	
	QStringList headers;
	headers << "key" << "timing" << "threshold" << "chatters";

	iModel->setHorizontalHeaderLabels(headers);
	ui.tableView->verticalHeader()->setVisible(false);
	ui.tableView->horizontalHeader()->setStretchLastSection(false);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
	ui.tableView->horizontalHeader()->setHighlightSections(false);
	ui.tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	ui.tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	ui.tableView->setModel(iModel);
	ui.tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	ui.tableView->setColumnWidth(0, 20);

	int v[4] = { RC_VERSION };

	ui.version_label->setText("v" +
		QString::number(v[0]) + "." +
		QString::number(v[1]) + "." +
		QString::number(v[2]) + "." +
		QString::number(v[3]));

	QObject::connect(ui.lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(update_ms_threshold(const QString &)));
	QObject::connect(ui.actionQuit, &QAction::triggered, this, &antikc::quit_app);
	QObject::connect(ui.actionPreferences, &QAction::triggered, this, &antikc::open_preferences);

	ui.lineEdit->setMaxLength(4);
	QRegExpValidator *rxv = new QRegExpValidator(QRegExp("\\d*"), this);
	ui.lineEdit->setValidator(rxv);

	//attempts hook
	if (!(h_handle = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)h_callback, 0, 0)))
	{
		DWORD err = GetLastError();
		LPSTR msg_buffer = nullptr;
		size_t s = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, err, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&msg_buffer, 0, NULL);

		std::string msg(msg_buffer, s);
		MessageBoxA(NULL, msg.c_str(), "HookError", MB_ICONWARNING);
	}
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
			if (antikc::keystats.size() == 0)
			{
				antikc::keystats.push_back(getNewKeystat(det->vkCode));
				antikc::updateView();

				return ALLOW_INPUT;
			}

			//lookup this key in our list
			for (auto i = antikc::keystats.begin(), end = antikc::keystats.end(); i != end; i++)
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

						return BLOCK_INPUT;
					}
					else //nope, just register its timing
					{
						i->timing = boop.QuadPart;

						return ALLOW_INPUT;
					}
				}
				else if(i->code == det->vkCode)
					return ALLOW_INPUT;
			}

			//we don't find this key in the list so we add it
			antikc::keystats.push_back(getNewKeystat(det->vkCode));
			antikc::updateView();			
		}
		//keep track of keyup/keydowns
		else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
		{
			//lookup this key in our list
			for (auto i = antikc::keystats.begin(), end = antikc::keystats.end(); i != end; i++)
			{
				//we found our key in our list - meaning it has already been pressed
				if (i->code == det->vkCode)
					i->down = false;
			}
		}
		return CallNextHookEx(NULL, nCode, wParam, lParam);
	}
}

bool sort_compare(antikc::_keystat &first, antikc::_keystat &second)
{
	if (first.chatters.count > second.chatters.count)
		return true;
	return false;
}

antikc::_keystat getNewKeystat(DWORD vkCode)
{
	antikc::_keystat newks;
	LARGE_INTEGER boop;
	QueryPerformanceCounter(&boop);
	newks.timing = boop.QuadPart;
	newks.threshold = global_threshold;
	newks.code = vkCode;
	newks.chatters.count = 0;

	return newks;
}

void antikc::updateView()
{
	int i = 0;
	antikc::keystats.sort(sort_compare);

	for each (auto keystat in antikc::keystats)
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

void antikc::quit_app()
{
	exit(0);
}

void antikc::open_preferences()
{
	pref = new Preferences();
	pref->setWindowFlags(Qt::WindowSystemMenuHint);	
	pref->exec();
}

antikc::~antikc()
{
	UnhookWindowsHookEx((HHOOK)h_handle);
	delete iModel;
}
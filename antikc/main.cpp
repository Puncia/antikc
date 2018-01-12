#include "antikc.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	antikc w;
	w.show();
	return a.exec();
}
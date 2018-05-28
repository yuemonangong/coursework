#include "Onitama.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Onitama w;
	w.show();
	return a.exec();
}

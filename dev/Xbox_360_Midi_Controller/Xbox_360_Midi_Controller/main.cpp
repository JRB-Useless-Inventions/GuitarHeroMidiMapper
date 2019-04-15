#include "guiMain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	guiMain w;
	w.show();

	while (true) {
	}
	return a.exec();
}

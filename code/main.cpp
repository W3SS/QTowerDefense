#include <QtGui>
#include "MainWindow.h"

int main (int argc, char* argv[]) {
    QApplication a(argc, argv);

    //QLabel l(m.all2[0]);
    //l.show();

    MainWindow mw;
    mw.show();

    return a.exec();
}

#include <QtGui/QApplication>
#include "mainwifiusers.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWifiUsers w;
    w.show();
    
    return a.exec();
}

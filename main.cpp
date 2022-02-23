#include "nokiamanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NokiaManager w;
    w.show();
    return a.exec();
}

#include "loginwindow.h"
#include "storemanagerwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginWindow w;
    StoreManager m;
    w.show();
    return a.exec();
}

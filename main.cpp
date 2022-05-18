#include "storemanager.h"
#include "logindialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog w;
    StoreManager m;
    w.show();
    return a.exec();
}

#include "storemanagerwindow.h"
#include "ui_storemanagerwindow.h"

storeManagerWindow::storeManagerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::storeManagerWindow)
{
    ui->setupUi(this);
}

storeManagerWindow::~storeManagerWindow()
{
    delete ui;
}

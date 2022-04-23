#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>


loginWindow::loginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}


void loginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_pasword->text();

    if ( username == "storemanager" && password == "admin")
    {
       QMessageBox::information(this, "Login", "You have Logged In");

      StoreManagerWindow = new StoreManager;
      StoreManagerWindow->show();
      this->close();


    }
    else
    {
        QMessageBox::warning(this, "Login", "Invalid Login Info");


    }

}


void loginWindow::on_lineEdit_pasword_returnPressed()
{
    on_pushButton_login_clicked();
}


void loginWindow::on_lineEdit_username_returnPressed()
{
    on_pushButton_login_clicked();
}


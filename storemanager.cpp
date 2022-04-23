#include "storemanager.h"
#include "ui_storemanager.h"
#include <QMessageBox>
#include "salesreport.h"

StoreManager::StoreManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StoreManager)
{
    ui->setupUi(this);
}

StoreManager::~StoreManager()
{
    delete ui;
}

/*void StoreManager::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");                          //Connecting to MySQL Database

    db.setHostName("127.0.0.1");
    db.setDatabaseName("qt5");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("");

    if (db.open())
    {
        QMessageBox::information(this, "Connected", "Database connected successfully");



    }
    else
    {
        QMessageBox::information(this, "Not Connected", "Database is not connected");


    }


}*/


void  StoreManager::on_pushButton_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("");

    if(!db.open())
    {
        QMessageBox::information(this, "Not Connected", "Database is not connected");

    }
    else
    {
        QMessageBox::information(this, "Connected", "Database connected successfully");

    }

}

void StoreManager::on_actionSales_Report_triggered()
{
    SalesReportWindow = new SalesReport;
    SalesReportWindow->show();
}


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


void  StoreManager::on_pushButton_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/mitch/BulkClub-System/BulkClubProject.db");

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

}


void StoreManager::on_sales_report_clicked()
{
    SalesReportWindow = new SalesReport;
    SalesReportWindow->show();
}


void StoreManager::on_membership_expiry_search_clicked()
{
    expiryWindow = new MembershipExpiry;
    expiryWindow->show();
}


void StoreManager::on_member_purchases_clicked()
{
    purchasesWindow = new memberPurchases;
    purchasesWindow->show();
}


void StoreManager::on_member_rebates_clicked()
{
    rebateDisplay = new rebateWindow;
    rebateDisplay->show();
}


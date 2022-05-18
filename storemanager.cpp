#include "storemanager.h"
#include "ui_storemanager.h"
#include <QMessageBox>

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


<<<<<<< HEAD
void  StoreManager::on_pushButton_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C:/Users/gpala_zdi8b1w/BulkClub-System/BulkClubProject.db");


    if(!db.open())
    {
        QMessageBox::information(this, "Not Connected", "Database is not connected");

    } else
    {
        QMessageBox::information(this, "Connected", "Database connected successfully");

    }

}

=======
>>>>>>> 6e94b28488d84adc6e5302c88a8bd2e1c65c6b1b
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

void StoreManager::on_item_inventory_clicked()
{
    itemDisplayWindow = new itemDisplay;
    itemDisplayWindow->show();
}

void StoreManager::on_new_purchase_clicked()
{
    purchaseWindow = new newPurchase;
    purchaseWindow->show();
}



void StoreManager::on_logout_clicked()
{
    close();

}


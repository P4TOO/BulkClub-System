#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
#include "salesreport.h"
#include "managemembers.h"
#include "memberpurchases.h"
Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users/luisr/OneDrive/Desktop/QT stuff/BulkClub-System_v6/BulkClubProject.db");

    if(!db.open())
    {
        QMessageBox::information(this, "Not Connected", "Database is not connected");
    }
    else
    {
        QMessageBox::information(this, "Connected", "Database connected successfully");
    }
}

void Admin::on_actionSales_Report_triggered()
{
    SalesReportWindow = new SalesReport;
    SalesReportWindow->show();
}



void Admin::on_manageMembersPushButton_clicked()
{
    ManageMembersWindow = new managemembers;
    ManageMembersWindow->show();
}

/*
void Admin::on_memberUpgrade_clicked()
{
    MemberUpgradeWindow = new memberupgrade;
    MemberUpgradeWindow->show();
}
 */


void Admin::on_exitButton_clicked()
{
    this->close();

}


void Admin::on_ManageInventoryPushbutton_clicked()
{
    inventoryEditWindow = new ManageInventory;
    inventoryEditWindow->show();
}


void Admin::on_actionSave_triggered()
{
    QMessageBox::information(this, "Save", "Success, all changes saved");
}


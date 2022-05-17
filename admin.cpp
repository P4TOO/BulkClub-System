#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
#include "salesreport.h"
#include "managemembers.h"

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
    db.setDatabaseName("C://Users/luisr/OneDrive/Desktop/QT stuff/BulkClub-System_v3/BulkClubProject.db");

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

void Admin::on_actionManage_Members_triggered()
{
    ManageMembersWindow = new managemembers;
    ManageMembersWindow->show();
}



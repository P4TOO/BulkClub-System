#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "salesreport.h"
#include "managemembers.h"
#include "manageinventory.h"
#include "memberupgrade.h"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_pushButton_clicked();

    void on_actionSales_Report_triggered();

    void on_manageMembersPushButton_clicked();

    void on_exitButton_clicked();


    void on_ManageInventoryPushbutton_clicked();

    //void on_memberUpgrade_clicked();

    void on_actionSave_triggered();

private:
    Ui::Admin *ui;
    SalesReport* SalesReportWindow = NULL;
    managemembers* ManageMembersWindow = NULL;
    ManageInventory* inventoryEditWindow = NULL;
    memberupgrade* MemberUpgradeWindow = NULL;

};

#endif // ADMIN_H

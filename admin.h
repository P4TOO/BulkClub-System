#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "salesreport.h"
#include "managemembers.h"
<<<<<<< HEAD
#include "manageinventory.h"

=======
#include "memberupgrade.h"
>>>>>>> a48879b9c033f01e86ea324fa9739fcb33c354c8

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

<<<<<<< HEAD
    void on_addMembers_clicked();

    void on_ManageInventoryPushbutton_clicked();

=======
    //void on_memberUpgrade_clicked();
>>>>>>> a48879b9c033f01e86ea324fa9739fcb33c354c8
private:
    Ui::Admin *ui;
    SalesReport* SalesReportWindow = NULL;
    managemembers* ManageMembersWindow = NULL;
<<<<<<< HEAD
    ManageInventory* inventoryEditWindow = NULL;
=======
    memberupgrade* MemberUpgradeWindow = NULL;
>>>>>>> a48879b9c033f01e86ea324fa9739fcb33c354c8

};

#endif // ADMIN_H

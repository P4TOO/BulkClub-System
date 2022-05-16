#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "salesreport.h"
#include "managemembers.h"
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

    void on_actionManage_Members_triggered();

private:
    Ui::Admin *ui;
    SalesReport* SalesReportWindow = NULL;
    managemembers* ManageMembersWindow = NULL;
    //PurchasesChart* PurchasesChartWindow = NULL;
    //ItemChart* ItemChartWindow = NULL;
   // ExecutiveRebate* ExecutiveRebateWindow = NULL;

};

#endif // ADMIN_H

#ifndef STOREMANAGER_H
#define STOREMANAGER_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "salesreport.h"
#include "membershipexpiry.h"
#include "memberpurchases.h"
#include "itemdisplay.h"

namespace Ui {
class StoreManager;
}

class StoreManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit StoreManager(QWidget *parent = nullptr);
    ~StoreManager();

private slots:
    void on_pushButton_clicked();

    //void on_actionSales_Report_triggered();

    void on_sales_report_clicked();

    void on_membership_expiry_search_clicked();

    void on_member_purchases_clicked();

   // void on_item_inventory_clicked();

private:
    Ui::StoreManager *ui;
    SalesReport* SalesReportWindow = NULL;
    MembershipExpiry* expiryWindow = NULL;
    memberPurchases* purchasesWindow = NULL;
    //itemDisplay* itemDisplayWindow = NULL;

};

#endif // STOREMANAGER_H

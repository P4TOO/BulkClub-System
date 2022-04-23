#ifndef STOREMANAGER_H
#define STOREMANAGER_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "salesreport.h"

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

    void on_actionSales_Report_triggered();

private:
    Ui::StoreManager *ui;
    SalesReport* SalesReportWindow = NULL;

};

#endif // STOREMANAGER_H

#include "memberupgrade.h"
#include "ui_memberupgrade.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>

memberupgrade::memberupgrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::memberupgrade)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C:/Users/gpala_zdi8b1w/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,

    db.open();                                                                  //the .db file should be kept within the repository for now

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT Member_Name, Membership_ID, Current_Rebate, Membership_Type "
                  "FROM Members "
                  "WHERE Membership_Type='Executive' AND Current_Rebate < 60.00");
    query.exec();

    model->setQuery(std::move(query));

    int downgradeCount = model->rowCount(invalidIndex);
    QString downgradeString = "Downgrades: ";
    downgradeString.append(QString::number(downgradeCount));
    ui->downgradeLabel->setText(downgradeString);

    ui->tableView->setModel(model);

    QSqlQueryModel * model2 = new QSqlQueryModel();
    QSqlQuery query2(db);
    query2.prepare("SELECT (SELECT Member_Name FROM Members WHERE Members.Membership_ID=Sales_Record.Membership_Number) AS Member_Name,Membership_Number, SUM(Quantity_Purchased * Sales_Price) AS Total_Spendings, (SELECT Membership_Type FROM Members WHERE Members.Membership_ID=Sales_Record.Membership_Number)AS Membership_Type FROM Sales_Record "

                   " GROUP BY Membership_Number HAVING Total_Spendings > 2750.00 AND Membership_Type = 'Regular'");

    query2.exec();

    model2->setQuery(std::move(query2));

    int upgradeCount = model2->rowCount(invalidIndex);
    QString upgradeString = "Upgrades: ";
    upgradeString.append(QString::number(upgradeCount));
    ui->upgradeLabel->setText(upgradeString);
    ui->tableView_2->setModel(model2);
}

memberupgrade::~memberupgrade()
{
    delete ui;
}

void memberupgrade::on_cancelButton_clicked()
{
    close();
}

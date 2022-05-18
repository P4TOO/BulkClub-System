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
    query.prepare("SELECT Member_Name, Membership_ID, Current_Rebate "
                  "FROM Members "
                  "WHERE Membership_Type='Executive' AND Current_Rebate < 10.00");
    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);

    QSqlQueryModel * model2 = new QSqlQueryModel();
    QSqlQuery query2(db);
    query2.prepare("SELECT Membership_Number, SUM(Quantity_Purchased * Sales_Price)"
                  "FROM Inventory "
                  // "WHERE "
                   "GROUP BY Membership_Number");

    query2.exec();

    model2->setQuery(std::move(query2));

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

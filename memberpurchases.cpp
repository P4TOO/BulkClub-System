#include "memberpurchases.h"
#include "ui_memberpurchases.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>

memberPurchases::memberPurchases(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::memberPurchases)
{
    ui->setupUi(this);
}

memberPurchases::~memberPurchases()
{
    delete ui;
}

void memberPurchases::on_idSearchButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/zacal/CS1C/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for now

    QString ID = ui->memberIDLineEdit->text();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Inventory WHERE Membership_Number=(:ID)");
    query.bindValue(":ID",ID);
    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
}


void memberPurchases::on_nameSearchButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/zacal/CS1C/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for now

    QString name = ui->memberNameLineEdit->text();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    QSqlRecord record;
    query.prepare("SELECT * FROM Members WHERE Member_Name=(:name)");//This query is for getting the memberID that corresponds to the entered name
    query.bindValue(":name",name);
    query.exec();
    qDebug() << name;

    model->setQuery(std::move(query));
    record = model->record(0);
    QString id = record.value(1).toString();
    qDebug() << id;
    QSqlQuery query2(db);
    query2.prepare("SELECT * FROM Inventory WHERE Membership_Number=(:ID)");//uses the fetched ID to check for purchases associated with it
    query2.bindValue(":ID",id);
    query2.exec();

    QSqlQueryModel * model2 = new QSqlQueryModel();
    model2->setQuery(std::move(query2));

    ui->tableView->setModel(model2);
}


void memberPurchases::on_cancelButton_clicked()
{
    close();
}


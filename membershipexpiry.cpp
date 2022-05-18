#include "membershipexpiry.h"
#include "ui_membershipexpiry.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>

MembershipExpiry::MembershipExpiry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MembershipExpiry)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users/luisr/OneDrive/Desktop/QT stuff/BulkClub-System_v6/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for no

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Members");
    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

MembershipExpiry::~MembershipExpiry()
{
    delete ui;
}



void MembershipExpiry::on_searchButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users/luisr/OneDrive/Desktop/QT stuff/BulkClub-System_v6/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for now

    QString date = ui->dateLineEdit->text();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Members WHERE Membership_Expiry=(:date)");
    query.bindValue(":date",date);
    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);

}


void MembershipExpiry::on_cancelButton_clicked()
{
    close();
}


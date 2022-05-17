#include "managemembers.h"
#include "ui_managemembers.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QMessageBox>
#include "addmember.h"
managemembers::managemembers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managemembers)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/mitch/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for now

    QSqlQueryModel * model = new QSqlQueryModel();
   //model is readonly access to query results
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Members");

    query.exec(); //query must be active before being moved into the model

    model->setQuery(std::move(query));
    ui->tableView->setModel(model);
}

managemembers::~managemembers()
{
    delete ui;
}

void managemembers::on_searchPushButton_clicked()
{
    QString input = ui->searchLineEdit->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/gpala_zdi8b1w/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for now

    QSqlQueryModel * model = new QSqlQueryModel();
   //model is readonly access to query results
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Members WHERE Membership_ID =(:input)");
    query.bindValue(":input", input);

    query.exec(); //query must be active before being moved into the model

    model->setQuery(std::move(query));
    ui->tableView->setModel(model);

}

void managemembers::on_DisplayAllPushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/gpala_zdi8b1w/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for now

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Members");

    query.exec(); //query must be active before being moved into the model

    model->setQuery(std::move(query));
    ui->tableView->setModel(model);
}




void managemembers::on_AddMemberButton_clicked()
{
    addMemberWindow = new AddMember;
    addMemberWindow->show();
}


void managemembers::on_deletePushButton_clicked()
{
    QString id = ui->deleteMemberLineEdit->text();

   if( QMessageBox::question(this, "Remove Member", "Are you sure you want to delete this member?"))
   {
       QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName("C:/Users/gpala_zdi8b1w/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
       db.open();                                                                  //the .db file should be kept within the repository for now


       QSqlQuery query(db);
       query.prepare("DELETE FROM Members WHERE MEMBERSHIP_ID = (:id)" );
       query.bindValue(":id", id);

       query.exec(); //query must be active before being moved into the model

       if (!query.exec() )
       {
           QMessageBox::warning(this, "Query Error", "Query not executed");
       }

       else
       {
           QMessageBox::information(this, "Member Deleted", "Success");


       }

       QSqlQueryModel * model = new QSqlQueryModel();

       query.prepare("SELECT * FROM Members");

       query.exec(); //query must be active before being moved into the model

       model->setQuery(std::move(query));
       ui->tableView->setModel(model);

   }

}



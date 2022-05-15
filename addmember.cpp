#include "addmember.h"
#include "ui_addmember.h"
#include <QRandomGenerator>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

AddMember::AddMember(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddMember)
{
    ui->setupUi(this);


}

AddMember::~AddMember()
{
    delete ui;
}

void AddMember::on_pushButton_2_clicked()
{
    this->close();
}


void AddMember::on_addMemberPushButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString type = ui->typeLineEdit->text();
    QString expiry = ui->ExpiryLineEdit->text();
   int id = QRandomGenerator::global()->bounded(11111, 99999);

   if (name == "" | type == "" | expiry == "")
   {
       QMessageBox::warning(this, "Empty field", "One of your fields is empty");
   }
else
   {
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("C://Users/luisr/OneDrive/Desktop/QT stuff/BulkClub-System_v3/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
   db.open();                                                                  //the .db file should be kept within the repository for now

   QSqlQuery query(db);
   //query.prepare("INSERT INTO Members (Member_Name, Membership_ID, Membership_Type, Membership_expiry) VALUES ( '(:name)', '(:id)', '(:type)' , '(:expiry)' ) ");
    query.prepare("INSERT INTO Members VALUES ((:name),(:id),(:type),(:expiry))");

   query.bindValue(":name", name);
   query.bindValue(":id", id);
   query.bindValue(":type", type);
   query.bindValue(":expiry", expiry);

   if (!query.exec() )
   {
       QMessageBox::warning(this, "Query Error", "Query not executed");
   }

   else
   {
       QMessageBox::information(this, "Member Added", "Success");

   }

   this->close();
}
}

void AddMember::on_ExpiryLineEdit_returnPressed()
{
    on_addMemberPushButton_clicked();
}


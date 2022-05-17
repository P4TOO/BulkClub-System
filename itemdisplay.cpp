#include "itemdisplay.h"
#include "ui_itemdisplay.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>

itemDisplay::itemDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::itemDisplay)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C:/Users/gpala_zdi8b1w/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,

    db.open();                                                                  //the .db file should be kept within the repository for now

    QSqlQueryModel * model = new QSqlQueryModel();

    QSqlQuery query(db);

    query.prepare("SELECT * FROM Inventory");

    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);

}

itemDisplay::~itemDisplay()
{
    delete ui;
}

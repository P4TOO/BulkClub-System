#include "salesreport.h"
#include "ui_salesreport.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>



SalesReport::SalesReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SalesReport)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/adriangomez/desktop/Bulk Project/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for now

    QSqlQueryModel * model = new QSqlQueryModel();
   //model is readonly access to query results
    QSqlRecord record;//record accesses records returned by a query
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Inventory");

    query.exec(); //query must be active before being moved into the model

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);


}

SalesReport::~SalesReport()
{
    delete ui;
}

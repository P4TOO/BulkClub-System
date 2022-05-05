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
    db.setDatabaseName("C:\\Users\\zacal\\CS1C\\BulkClub-System\\BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for now

    QSqlQueryModel * model = new QSqlQueryModel();
   //model is readonly access to query results
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Inventory");

    query.exec(); //query must be active before being moved into the model

    model->setQuery(std::move(query));

    QSqlRecord totalSalesRecord;//this record will hold an individual user data row
    int totalSalesIterator = 1;
    double salesPrice;
    double salesQuantity;
    double runningTotal = 0;
    do{
        totalSalesRecord = model->record(totalSalesIterator); //sets record to the row of the iterator in the model
        salesPrice = totalSalesRecord.value(3).toDouble(); //value at index 3 in the row should be Sales_Price
        salesQuantity = totalSalesRecord.value(4).toDouble(); //value at index 4 in the row should be Quantity_Purchased
        runningTotal += salesPrice * salesQuantity;
        totalSalesIterator++;
    }while (!totalSalesRecord.isNull(3));
    QString finalTotal = finalTotal.number(runningTotal,'f',2);//sets a formatted total to a string that can be passed to the totalSalesNum label

    ui->tableView->setModel(model);

    ui->totalSalesNum->setText(finalTotal);


}

SalesReport::~SalesReport()
{
    delete ui;
}

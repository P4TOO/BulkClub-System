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

    QSqlRecord totalSalesRecord;//this record will hold an individual user data row
    int totalSalesIterator = 0;
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
    runningTotal += runningTotal * 0.0775;
    QString finalTotal = finalTotal.number(runningTotal,'f',2);//sets a formatted total to a string that can be passed to the totalSalesNum label
    finalTotal.prepend("Total Purchases +tax: ");
    ui->tableView->setModel(model);
    ui->totalLabel->setText(finalTotal);
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

    model->setQuery(std::move(query));
    record = model->record(0);
    QString id = record.value(1).toString();
    QSqlQuery query2(db);
    query2.prepare("SELECT * FROM Inventory WHERE Membership_Number=(:ID)");//uses the fetched ID to check for purchases associated with it
    query2.bindValue(":ID",id);
    query2.exec();
    qDebug() << id;

    QSqlQueryModel * model2 = new QSqlQueryModel();
    model2->setQuery(std::move(query2));

    QSqlRecord totalSalesRecord;//this record will hold an individual user data row
    int totalSalesIterator = 0;
    double salesPrice;
    double salesQuantity;
    double runningTotal = 0;
    do{
        totalSalesRecord = model2->record(totalSalesIterator); //sets record to the row of the iterator in the model
        salesPrice = totalSalesRecord.value(3).toDouble(); //value at index 3 in the row should be Sales_Price
        salesQuantity = totalSalesRecord.value(4).toDouble(); //value at index 4 in the row should be Quantity_Purchased
        runningTotal += salesPrice * salesQuantity;
        totalSalesIterator++;
    }while (!totalSalesRecord.isNull(3));
    runningTotal += runningTotal * 0.0775;
    QString finalTotal = finalTotal.number(runningTotal,'f',2);//sets a formatted total to a string that can be passed to the totalSalesNum label
    finalTotal.prepend("Total Purchases +tax: ");
    ui->tableView->setModel(model2);
    ui->totalLabel->setText(finalTotal);
}


void memberPurchases::on_cancelButton_clicked()
{
    close();
}


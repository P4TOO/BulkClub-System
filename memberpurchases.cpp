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

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C:/Users/zacal/CS1C/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,

    db.open();                                                                  //the .db file should be kept within the repository for now

    QSqlQueryModel * model0 = new QSqlQueryModel();
   //model is readonly access to query results
    QSqlQuery query(db);
    query.prepare("SELECT Membership_Number, (SELECT Member_Name from Members WHERE Members.Membership_ID=Sales_Record.Membership_Number) as Member_Name, SUM (sales_price* quantity_purchased * 1.0775) as Total_Purchases FROM Sales_Record GROUP BY Membership_number ORDER BY Membership_number");


    query.exec(); //query must be active before being moved into the model

    model0->setQuery(std::move(query));

    ui->tableView->setModel(model0);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlRecord totalMemberSalesRecord;
    int totalSalesIterator1 = 0;
    double salesPrice1 = 0;
    //int salesQuantity1 = 0;
    double runningTotal1 = 0;

    do{
            totalMemberSalesRecord = model0->record(totalSalesIterator1); //sets record to the row of the iterator in the model
            salesPrice1 = totalMemberSalesRecord.value(1).toDouble(); //value at index 3 in the row should be Sales_Price
            runningTotal1 += salesPrice1;
            totalSalesIterator1++;
        }while (!totalMemberSalesRecord.isNull(1));

    QString finalTotal = finalTotal.number(runningTotal1,'f',2);//sets a formatted total to a string that can be passed to the totalSalesNum label
    finalTotal.prepend("Total Purchases + tax: ");
    ui->totalLabel->setText(finalTotal);
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
    query.prepare("SELECT * FROM Sales_Record WHERE Membership_Number=(:ID)");
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
    finalTotal.prepend("Total Purchases + tax: ");
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
    query2.prepare("SELECT * FROM Sales_Record WHERE Membership_Number=(:ID)");//uses the fetched ID to check for purchases associated with it
    query2.bindValue(":ID",id);
    query2.exec();

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
    finalTotal.prepend("Total Purchases + tax: ");
    ui->tableView->setModel(model2);
    ui->totalLabel->setText(finalTotal);
}


void memberPurchases::on_cancelButton_clicked()
{
    close();
}


void memberPurchases::on_DisplayAllPushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C:/Users/zacal/CS1C/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,

    db.open();                                                                  //the .db file should be kept within the repository for now

    QSqlQueryModel * model0 = new QSqlQueryModel();
   //model is readonly access to query results
    QSqlQuery query(db);
    query.prepare("SELECT Membership_Number, (SELECT Member_Name from Members WHERE Members.Membership_ID=Sales_Record.Membership_Number) as Member_Name, SUM (sales_price* quantity_purchased * 1.0775) as Total_Purchases FROM Sales_Record GROUP BY Membership_number ORDER BY Membership_number");

    query.exec(); //query must be active before being moved into the model

    model0->setQuery(std::move(query));

    ui->tableView->setModel(model0);

    QSqlRecord totalMemberSalesRecord;
    int totalSalesIterator1 = 0;
    double salesPrice1 = 0;
    //int salesQuantity1 = 0;
    double runningTotal1 = 0;

    do{
            totalMemberSalesRecord = model0->record(totalSalesIterator1); //sets record to the row of the iterator in the model
            salesPrice1 = totalMemberSalesRecord.value(1).toDouble(); //value at index 3 in the row should be Sales_Price
            runningTotal1 += salesPrice1;
            totalSalesIterator1++;
        }while (!totalMemberSalesRecord.isNull(1));

    QString finalTotal = finalTotal.number(runningTotal1,'f',2);//sets a formatted total to a string that can be passed to the totalSalesNum label
    finalTotal.prepend("Total Purchases + tax: ");
    ui->totalLabel->setText(finalTotal);
}


void memberPurchases::on_memberIDLineEdit_returnPressed()
{
    memberPurchases::on_idSearchButton_clicked();
}


void memberPurchases::on_memberNameLineEdit_returnPressed()
{
    memberPurchases::on_nameSearchButton_clicked();
}


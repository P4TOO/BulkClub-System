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


    query.prepare("SELECT item_purchased, SUM(sales_price* quantity_purchased) AS Total_Price , SUM(quantity_purchased) AS Total_Quantity FROM Sales_Record GROUP BY Item_Purchased ORDER BY Total_Price DESC");

    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

itemDisplay::~itemDisplay()
{
    delete ui;
}


void itemDisplay::on_searchButton_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/gpala_zdi8b1w/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for now

    QString item = ui->itemSearchBar->text();
    QSqlQueryModel * model2 = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM sales_record WHERE Item_Purchased=(:item)");
    query.bindValue(":item",item);
    query.exec();

    model2->setQuery(std::move(query));

    ui->tableView->setModel(model2);

    QSqlRecord totalSalesAndQuantityRecord;
    int totalSalesIterator = 0;
    double salesPrice = 0;
    int salesQuantity = 0;
    double priceTotal = 0;
    int totalQuantity = 0;

    do {
        totalSalesAndQuantityRecord = model2 -> record(totalSalesIterator);
        salesPrice = totalSalesAndQuantityRecord.value(3).toDouble(); //value at index 3 in the row should be Sales_Price
        salesQuantity = totalSalesAndQuantityRecord.value(4).toInt(); //value at index 4 in the row should be Quantity_Purchased
        priceTotal += salesPrice * salesQuantity;
        totalQuantity += salesQuantity;
        totalSalesIterator++;

    } while (!totalSalesAndQuantityRecord.isNull(3));

    QString finalPriceTotal = finalPriceTotal.number(priceTotal, 'f', 2);
    finalPriceTotal.prepend("Total revenue for item: ");

    QString finalQuantityTotal =  finalQuantityTotal.number(totalQuantity, 'f', 0);
    finalQuantityTotal.prepend("Total quantity for item: ");

    ui->itemQuantityTotal->setText(finalQuantityTotal);
    ui->itemPriceTotal->setText(finalPriceTotal);

}




void itemDisplay::on_pushButton_clicked()
{
    this->close();
}


#include "rebatewindow.h"
#include "ui_rebatewindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>

rebateWindow::rebateWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rebateWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/zacal/CS1C/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for now

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Members WHERE Membership_Type='Executive'");
    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
}

rebateWindow::~rebateWindow()
{
    delete ui;
}

void rebateWindow::on_pushButton_clicked()
{
    close();
}


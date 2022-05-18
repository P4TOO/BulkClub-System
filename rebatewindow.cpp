#include "rebatewindow.h"
#include "ui_rebatewindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlRecord>

rebateWindow::rebateWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rebateWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C://Users/luisr/OneDrive/Desktop/QT stuff/BulkClub-System_v6/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();                                                                  //the .db file should be kept within the repository for now

    QSqlTableModel * model = new QSqlTableModel();
    model->setTable("Members");
    model->select();
    model->setFilter("Membership_Type='Executive'");
    model->setSort(1,Qt::AscendingOrder);
    model->select();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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


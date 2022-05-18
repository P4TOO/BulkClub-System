#include "manageinventory.h"
#include "ui_manageinventory.h"
#include <QModelIndex>
#include <QMessageBox>

ManageInventory::ManageInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageInventory)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/gpala_zdi8b1w/BulkClub-System/BulkClubProject.db");//This line and the previous connect to the sqlite database at this file location,

    db.open();                                                                  //the .db file should be kept within the repository for now
    model = new QSqlTableModel(NULL,db);
    model->setTable("Inventory");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    ui->RowToDel->setMaximum(model->rowCount(invalidIndex));
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->show();
}

ManageInventory::~ManageInventory()
{
    delete ui;
}



void ManageInventory::on_SaveButton_clicked()
{
    model->submitAll();
    QMessageBox::information(this, "Save", "Success, all changes saved");
}



void ManageInventory::on_Cancelbutton_clicked()
{
    model->revertAll();
    close();
}


void ManageInventory::on_AddRowButton_clicked()
{
    model->insertRows(model->rowCount(invalidIndex),1);
    ui->RowToDel->setMaximum(model->rowCount(invalidIndex));
}


void ManageInventory::on_DelRowButton_clicked()
{
    model->removeRows(ui->RowToDel->value()-1,1,invalidIndex);
    ui->RowToDel->setMaximum(model->rowCount(invalidIndex));
    model->submitAll();
}


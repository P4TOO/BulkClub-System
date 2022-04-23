#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "storemanager.h"
#include "salesreport.h"

QT_BEGIN_NAMESPACE
namespace Ui { class loginWindow; }
QT_END_NAMESPACE

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_lineEdit_pasword_returnPressed();

    void on_lineEdit_username_returnPressed();

private:
    Ui::loginWindow *ui;
    StoreManager* StoreManagerWindow = NULL;

};
#endif // LOGINWINDOW_H

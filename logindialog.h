#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H


#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>
#include "ui_loginwindow.h"
#include "storemanager.h"
#include "admin.h"



class LoginDialog : public QDialog {
    Q_OBJECT
private:



    QLabel* labelUsername;

    QLabel* labelPassword;

    QLineEdit* editUsername;

    QLineEdit* editPassword;

    QDialogButtonBox* buttons;

    void setUpGUI();

    StoreManager* StoreManagerWindow = NULL;
    Admin* adminWindow = NULL;

public:
    explicit LoginDialog(QWidget* parent = nullptr);
    void setUsername( QString& username );
    void setPassword( QString& password );
signals:
    void acceptLogin( QString& username, QString& password );
public slots:


    void slotAcceptLogin();
};

#endif // LOGINDIALOG_H

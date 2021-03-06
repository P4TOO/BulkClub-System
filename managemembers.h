#ifndef MANAGEMEMBERS_H
#define MANAGEMEMBERS_H

#include <QWidget>
#include "addmember.h"

namespace Ui {
class managemembers;
}

class managemembers : public QWidget
{
    Q_OBJECT

public:
    explicit managemembers(QWidget *parent = nullptr);
    ~managemembers();

private slots:
    void on_searchPushButton_clicked();

    void on_AddMemberButton_clicked();

    void on_deletePushButton_clicked();

    void on_DisplayAllPushButton_clicked();

    void on_searchLineEdit_returnPressed();

    void on_deleteMemberLineEdit_returnPressed();

    void on_ExitButton_clicked();

private:
    Ui::managemembers *ui;
    AddMember* addMemberWindow = NULL;
};

#endif // MANAGEMEMBERS_H

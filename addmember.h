#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QWidget>

namespace Ui {
class AddMember;
}

class AddMember : public QWidget
{
    Q_OBJECT

public:
    explicit AddMember(QWidget *parent = nullptr);
    ~AddMember();

private slots:
    void on_pushButton_2_clicked();

    void on_addMemberPushButton_clicked();

    void on_ExpiryLineEdit_returnPressed();

private:
    Ui::AddMember *ui;
};

#endif // ADDMEMBER_H

#ifndef SALESREPORT_H
#define SALESREPORT_H

#include <QWidget>

namespace Ui {
class SalesReport;
}

class SalesReport : public QWidget
{
    Q_OBJECT

public:
    explicit SalesReport(QWidget *parent = nullptr);
    ~SalesReport();

private slots:
    void on_MemberTypePushButton_clicked();

    void on_DatePushButton_clicked();

    void on_DatelineEdit_returnPressed();

    void on_ExitButton_clicked();

    void on_AllTimeButton_clicked();

private:
    Ui::SalesReport *ui;

};

#endif // SALESREPORT_H

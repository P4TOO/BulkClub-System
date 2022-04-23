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

private:
    Ui::SalesReport *ui;

};

#endif // SALESREPORT_H

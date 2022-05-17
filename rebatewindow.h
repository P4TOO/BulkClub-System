#ifndef REBATEWINDOW_H
#define REBATEWINDOW_H

#include <QWidget>

namespace Ui {
class rebateWindow;
}

class rebateWindow : public QWidget
{
    Q_OBJECT

public:
    explicit rebateWindow(QWidget *parent = nullptr);
    ~rebateWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::rebateWindow *ui;
};

#endif // REBATEWINDOW_H

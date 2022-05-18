#ifndef ITEMDISPLAY_H
#define ITEMDISPLAY_H

#include <QDialog>

namespace Ui {
class itemDisplay;
}

class itemDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit itemDisplay(QWidget *parent = nullptr);
    ~itemDisplay();

private slots:
    //void on_pushButton_clicked();

    void on_searchButton_clicked();


    void on_pushButton_clicked();

private:
    Ui::itemDisplay *ui;
};

#endif // ITEMDISPLAY_H

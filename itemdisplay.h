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

private:
    Ui::itemDisplay *ui;
};

#endif // ITEMDISPLAY_H

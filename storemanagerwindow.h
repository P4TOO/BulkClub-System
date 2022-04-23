#ifndef STOREMANAGERWINDOW_H
#define STOREMANAGERWINDOW_H

#include <QMainWindow>

namespace Ui {
class storeManagerWindow;
}

class storeManagerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit storeManagerWindow(QWidget *parent = nullptr);
    ~storeManagerWindow();

private:
    Ui::storeManagerWindow *ui;
};

#endif // STOREMANAGERWINDOW_H

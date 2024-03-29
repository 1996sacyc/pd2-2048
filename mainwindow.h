#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "game.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_startbutton_clicked();

private:
    Ui::MainWindow *ui;
    game begin;
};

#endif // MAINWINDOW_H

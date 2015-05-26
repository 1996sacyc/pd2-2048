#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startbutton,SIGNAL(clicked()),this,SLOT(on_startbutton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startbutton_clicked(){
    begin.show();
    this->close();
} /*start the game button*/

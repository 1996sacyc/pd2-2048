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
    this->setStyleSheet("background-color: white;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startbutton_clicked(){
    begin.show();
    begin.Gamestart();
    this->close();
} /*start the game button*/

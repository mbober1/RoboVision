#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonClose_clicked()
{
    this->close();
}

void MainWindow::on_pushButtonConnect_clicked()
{
    std::string IP_ADDRES = ui->lineEditAdress->text().toStdString();
    qDebug() << IP_ADDRES.c_str();
    ui->pushButtonConnect->setText("Disconnect");
    ui->labelConnectionStatus->setText("CONNECTED");
}

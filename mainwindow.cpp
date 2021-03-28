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

//void MainWindow::leftX(double value) {
//    ui->progressBarLeftX->setValue((int)(value * 100));
//}

//void MainWindow::leftY(double value) {
//    ui->progressBarLeftY->setValue((int)(value * 100));
//}

//void MainWindow::gamepadStatus(bool status) {
//    ui->labelGamepadStatus->setText(status?"Gamepad connected":"Gamepad disconnected");
//}

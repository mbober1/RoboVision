#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <string>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditPort->setInputMask("99000");
    ui->lineEditAdress->setInputMask("900.900.900.900");

    QObject::connect(tcp.socket, &QTcpSocket::stateChanged, [this](QAbstractSocket::SocketState state) {
        this->changeConnectionStatus(state);
    });

    connect(tcp.socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &MainWindow::connectionError);

    QObject::connect(&tcp, &clientTCP::latencyChanged, [this](int latency) {
        ui->lcdNumberPing->display(latency);
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonConnect_clicked()
{
    qDebug() << tcp.socket->state();
    if(tcp.socket->state() == QAbstractSocket::ConnectedState) tcp.socket->close();
    else tcp.initConnection(ui->lineEditAdress->text(), ui->lineEditPort->text().toInt());
}

void MainWindow::changeConnectionStatus(QAbstractSocket::SocketState state) {
    qDebug() << "dupa" << state;
    switch (state)
    {
    case QAbstractSocket::ConnectedState:
        ui->pushButtonConnect->setText("Disconnect");
        ui->labelConnectionStatus->setText("CONNECTED");
        break;

    case QAbstractSocket::UnconnectedState:
        ui->pushButtonConnect->setText("Connect");
        ui->labelConnectionStatus->setText("DISCONNECTED");
        break;

    case QAbstractSocket::ConnectingState:
    case QAbstractSocket::HostLookupState:
        ui->pushButtonConnect->setText("Disconnect");
        ui->labelConnectionStatus->setText("CONNECTING...");
        break;
    
    default:
        qDebug() << state;
        break;
    }
}

// void MainWindow::leftX(double value) {
//     ui->progressBarBattery->setValue((int)(value * 100));
// }

// void MainWindow::leftY(double value) {
//    ui->progressBarBattery->setValue((int)(value * 100));
// }

//void MainWindow::gamepadStatus(bool status) {
//    ui->labelGamepadStatus->setText(status?"Gamepad connected":"Gamepad disconnected");
//}


void MainWindow::connectionError(QAbstractSocket::SocketError error) {
    QString mess = "Connection error occured! Please contact your administartor";

    switch (error)
    {
    case QAbstractSocket::ConnectionRefusedError:
        mess += error;
        break;
    
    default:
        break;
    }
    QMessageBox::critical(this, "Connection error", mess);
}
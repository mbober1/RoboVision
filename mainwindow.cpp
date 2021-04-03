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
        this->toggleDataTimer();
        if(state == QAbstractSocket::ConnectedState) udp.init(ui->lineEditAdress->text(), ui->lineEditPort->text().toInt() - 1);
        else udp.close();
    });

    connect(joystick.m_gamepad, &QGamepad::connectedChanged, this, &MainWindow::toggleDataTimer);
    connect(udp.socket, &QUdpSocket::stateChanged, this, &MainWindow::toggleDataTimer);

    connect(tcp.socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &MainWindow::connectionError);

    QObject::connect(&tcp, &clientTCP::latencyChanged, [this](int latency) {
        ui->lcdNumberPing->display(latency);
    });

    connect(&dataTimer, &QTimer::timeout, this, &MainWindow::readData);
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

void MainWindow::readData() {
    qDebug() << joystick.m_gamepad->axisLeftY();
    udp.send(joystick.m_gamepad->axisLeftY()*100,joystick.m_gamepad->axisLeftX()*100);
}


void MainWindow::toggleDataTimer() {
    if(joystick.m_gamepad->isConnected() && tcp.socket->state() == QAbstractSocket::ConnectedState && udp.socket->state() == QAbstractSocket::ConnectedState) {
        dataTimer.start(17);
    } else dataTimer.stop();
}

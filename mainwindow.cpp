#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectiondialog.h"
#include <QDebug>
#include <string>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(tcp.socket, &QTcpSocket::stateChanged, [this](QAbstractSocket::SocketState state) {
        this->changeConnectionStatus(state);
        this->toggleDataTimer();
        if(state == QAbstractSocket::ConnectedState) udp.init();
        else udp.close();
    });

    connect(joystick.m_gamepad, &QGamepad::connectedChanged, this, &MainWindow::toggleDataTimer);
    connect(udp.socket, &QUdpSocket::stateChanged, this, &MainWindow::toggleDataTimer);
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::actionConnect);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::actionDisconnect);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(tcp.socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::errorOccurred), this, &MainWindow::connectionError);

    QObject::connect(&tcp, &clientTCP::latencyChanged, [this](int latency) {
       ui->lcdNumberPing->display(latency);
    });

    connect(&dataTimer, &QTimer::timeout, this, &MainWindow::readData);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::actionConnect()
{
    ConnectionDialog dialog;
    dialog.setModal(true);
    if(dialog.exec() == QDialog::Accepted) {
        tcp.address = dialog.getAdress();
        tcp.port = dialog.getTcpPort();
        udp.address = dialog.getAdress();
        udp.port = dialog.getUdpPort();
    // if(tcp.socket->state() == QAbstractSocket::ConnectedState) tcp.socket->close();
    // else tcp.initConnection(ui->lineEditAdress->text(), ui->lineEditPort->text().toInt());
        tcp.initConnection();
    }
    // qDebug() << tcp.socket->state();
}

void MainWindow::actionDisconnect() {
    tcp.socket->close();
    udp.socket->close();
}

void MainWindow::changeConnectionStatus(QAbstractSocket::SocketState state) {
    switch (state)
    {
    case QAbstractSocket::ConnectedState:
        ui->actionConnect->setVisible(false);
        ui->actionDisconnect->setVisible(true);
        ui->actionDisconnect->setEnabled(true);
        ui->labelConnectionStatus->setText("CONNECTED");
        break;

    case QAbstractSocket::UnconnectedState:
        ui->actionConnect->setVisible(true);
        ui->actionDisconnect->setVisible(false);
        ui->labelConnectionStatus->setText("DISCONNECTED");
        break;

    case QAbstractSocket::ConnectingState:
    case QAbstractSocket::HostLookupState:
        ui->actionConnect->setVisible(false);
        ui->actionDisconnect->setVisible(true);
        ui->actionDisconnect->setEnabled(true);
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
    udp.send(joystick.m_gamepad->axisLeftY()*100,joystick.m_gamepad->axisLeftX()*100);
}


void MainWindow::toggleDataTimer() {
    if(joystick.m_gamepad->isConnected() && tcp.socket->state() == QAbstractSocket::ConnectedState && udp.socket->state() == QAbstractSocket::ConnectedState) {
        dataTimer.start(17);
    } else dataTimer.stop();
}

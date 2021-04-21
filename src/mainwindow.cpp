#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectiondialog.h"
#include <QDebug>
#include <string>
#include <QMessageBox>
#include <QDesktopServices>

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
    connect(&dataTimer, &QTimer::timeout, this, &MainWindow::readData);
    connect(&tcp, &clientTCP::closeConnection, this, &MainWindow::actionDisconnect);

    QObject::connect(&tcp, &clientTCP::latencyChanged, [this](int latency) {
       ui->lcdNumberPing->display(latency);
    });

    QObject::connect(&tcp, &clientTCP::batteryChanged, [this](int level) {
       ui->progressBarBattery->setValue(level);
    });

    QObject::connect(&tcp, &clientTCP::distanceChanged, [this](int distance) {
       ui->progressBarObstacle->setValue(distance);
    });

    QObject::connect(ui->actionGitHub, &QAction::triggered, [this] () {
       QDesktopServices::openUrl(QUrl("https://github.com/mbober1/RoboVision", QUrl::TolerantMode));
    });

}

MainWindow::~MainWindow() {
    qDebug() << "koniec";
    actionDisconnect();
    delete ui;
}


void MainWindow::actionConnect() {
    ConnectionDialog dialog;
    dialog.setModal(true);
    if(dialog.exec() == QDialog::Accepted) {
        tcp.address = dialog.getAdress();
        tcp.port = dialog.getTcpPort();
        udp.address = dialog.getAdress();
        udp.port = dialog.getUdpPort();
        tcp.initConnection();
    }
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
    QString mess = "Connection error occured! Please try again";

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

void MainWindow::keyPressEvent(QKeyEvent* event) {
    qDebug() << event->text();
}

void MainWindow::readData() {
    int nJoyX = joystick.m_gamepad->axisLeftX() * 100;
    int nJoyY = -joystick.m_gamepad->axisLeftY() * 100;

    // CONFIG
    // - fPivYLimt  : The threshold at which the pivot action starts
    //                This threshold is measured in units on the Y-axis
    //                away from the X-axis (Y=0). A greater value will assign
    //                more of the joystick's range to pivot actions.
    //                Allowable range: (0..+127)
    float fPivYLimit = 32.0;
                
    // TEMP VARIABLES
    float   nMotPremixL;    // Motor (left)  premixed output        (-128..+127)
    float   nMotPremixR;    // Motor (right) premixed output        (-128..+127)
    int     nPivSpeed;      // Pivot Speed                          (-128..+127)
    float   fPivScale;      // Balance scale b/w drive and pivot    (   0..1   )


    // Calculate Drive Turn output due to Joystick X input
    if (nJoyY >= 0) {
    // Forward
        nMotPremixL = (nJoyX>=0)? 127.0 : (127.0 + nJoyX);
        nMotPremixR = (nJoyX>=0)? (127.0 - nJoyX) : 127.0;
    } else {
    // Reverse
        nMotPremixL = (nJoyX>=0)? (127.0 - nJoyX) : 127.0;
        nMotPremixR = (nJoyX>=0)? 127.0 : (127.0 + nJoyX);
    }

    // Scale Drive output due to Joystick Y input (throttle)
    nMotPremixL = nMotPremixL * nJoyY/128.0;
    nMotPremixR = nMotPremixR * nJoyY/128.0;

    // Now calculate pivot amount
    // - Strength of pivot (nPivSpeed) based on Joystick X input
    // - Blending of pivot vs drive (fPivScale) based on Joystick Y input
    nPivSpeed = nJoyX;
    fPivScale = (abs(nJoyY)>fPivYLimit)? 0.0 : (1.0 - abs(nJoyY)/fPivYLimit);

    int left = (1.0-fPivScale)*nMotPremixL + fPivScale*( nPivSpeed);
    int right = (1.0-fPivScale)*nMotPremixR + fPivScale*(-nPivSpeed);

	printf("L: %d, R: %d\n", left, right);			
    udp.send(left, right);
}

void MainWindow::toggleDataTimer() {
    if(joystick.m_gamepad->isConnected() && tcp.socket->state() == QAbstractSocket::ConnectedState && udp.socket->state() == QAbstractSocket::ConnectedState) {
        dataTimer.start(50);
    } else dataTimer.stop();
}

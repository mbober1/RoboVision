#include "mytcp.hpp"

clientTCP::clientTCP(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(&timer, &QTimer::timeout, this, &clientTCP::ping);
}

void clientTCP::initConnection()
{
    qDebug() << "TCP Connecting...";
    socket->connectToHost(this->address, this->port);
}

void clientTCP::connected()
{
    qDebug() << "TCP Connected!";
    timer.start(1000);
}

void clientTCP::disconnected()
{
    qDebug() << "TCP Disconnected!";
    timer.stop();
}

void clientTCP::readyRead()
{
    // qDebug() << "Reading...";
    // qDebug() << socket->readAll();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-this->lastPing;
    emit latencyChanged(elapsed_seconds.count() * 1000);
}

void clientTCP::ping()
{
    socket->write("ping");
    this->lastPing = std::chrono::system_clock::now();
}
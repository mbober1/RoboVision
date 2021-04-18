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
    std::string x = socket->readAll().toStdString();
    qDebug() << "Odbieram: " << x.c_str();
    Packet* packet = Packet::decode(x);

    if (packet != nullptr) {
        switch (packet->getType())
        {
        case 'P': {
            qDebug() << "PONG!";
            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = end-this->lastPing;
            emit latencyChanged(elapsed_seconds.count() * 1000);
            break;
        }

        case 'B':
            emit batteryChanged(((BatteryPacket*)packet)->level);
            break;

        case 'D':
            emit distanceChanged(((DistancePacket*)packet)->distance);
            break;

        case 'S':
            qDebug() << "Speed:" << ((SpeedPacket*)packet)->left << "|" << ((SpeedPacket*)packet)->right;
            break;

        case 'C':
            emit closeConnection();
            break;
        
        default:
            qDebug() << "du[pa!";
            break;
        }

        delete packet;
    }
}

void clientTCP::ping()
{
    qDebug() << "PING!";
    std::string data = PingPacket().prepare();
    socket->write(data.c_str(), data.size());
    this->lastPing = std::chrono::system_clock::now();
}

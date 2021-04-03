#include "myudp.hpp"

clientUDP::clientUDP(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void clientUDP::init() {
    qDebug() << "UDP Connecting...";
    socket->connectToHost(this->address, this->port);
}

void clientUDP::close() {
    socket->close();
}

void clientUDP::send(int left, int right)
{   
    char buffer[50];
    sprintf(buffer, "L%3d;R%3d", left, right);
    socket->write(buffer);
}

void clientUDP::connected()
{
    qDebug() << "UDP Connected!";
    // timer.start(1000);
}

void clientUDP::disconnected()
{
    qDebug() << "UDP Disconnected!";
    // timer.stop();
}

void clientUDP::readyRead()
{
    // when data comes in
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());
    
    QHostAddress sender;
    quint16 senderPort;
    
    // qDebug() << socket->readAll();

    
    socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
    
    qDebug() << "Message from: " << sender.toString(); 
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
}

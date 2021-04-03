#include "myudp.hpp"

clientUDP::clientUDP(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);

    client.setAddress("192.168.31.255");
    
    socket->bind(client, 8090);
    
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void clientUDP::send(int left, int right)
{
    // QByteArray data;
    char buffer[50];
    sprintf(buffer, "L%d;R%d", left, right);
    // data.append(buffer);
    socket->writeDatagram(buffer, client, 8090);
}

void clientUDP::readyRead()
{
    // when data comes in
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());
    
    QHostAddress sender;
    quint16 senderPort;
    
    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize, 
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data. 
    // The sender's host address and port is stored in *address and *port 
    // (unless the pointers are 0).
    
    socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
    
    qDebug() << "Message from: " << sender.toString(); 
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
}
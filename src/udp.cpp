#include "udp.hpp"


/**
 * A constructor.
 * @param parent QWidget type parent.
 */
clientUDP::clientUDP(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}


/**
 * Initialize connection
 */
void clientUDP::init() {
    qDebug() << "UDP Connecting...";
    socket->connectToHost(this->address, this->port);
}


/**
 * Close connection
 */
void clientUDP::close() {
    socket->close();
}


/**
 * Send sterring data
 * @param left Left engine power 0-100
 * @param left Right engine power 0-100
 */
void clientUDP::send(int left, int right)
{   
    EnginePacket packet = EnginePacket(left, right);
    std::string data = packet.prepare();
    // qDebug() << data.c_str();
    socket->write(data.c_str());
}


/**
 * Connected status
 */
void clientUDP::connected()
{
    qDebug() << "UDP Connected!";
}


/**
 * Disconnected status
 */
void clientUDP::disconnected()
{
    qDebug() << "UDP Disconnected!";
}


/**
 * Incoming data handler
 */
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

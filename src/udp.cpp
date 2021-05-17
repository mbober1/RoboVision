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
#include "tcp.hpp"


/**
 * A constructor.
 * @param parent QWidget type parent.
 */
clientTCP::clientTCP(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(&timer, &QTimer::timeout, this, &clientTCP::ping);
}


/**
 * Initialize connection
 */
void clientTCP::initConnection()
{
    qDebug() << "TCP Connecting...";
    socket->connectToHost(this->address, this->port);
}


/**
 * Connected status
 */
void clientTCP::connected()
{
    qDebug() << "TCP Connected!";
    timer.start(1000);
}


/**
 * Disconnected status
 */
void clientTCP::disconnected()
{
    qDebug() << "TCP Disconnected!";
    timer.stop();
}


/**
 * Incoming data handler
 */
void clientTCP::readyRead()
{
    std::string data = socket->readAll().toStdString();
    // qDebug() << "Odbieram: " << data.c_str();


    int separator = data.find(';');
    // printf("Znalazłem separator na miejscu: %d\n", separator);
    
    while(separator != std::string::npos) {
        std::string parse = data.substr(0, separator);
        data.erase(0, separator + 1);
        // printf("Nowy string: %s\n", parse.c_str());
        
        Packet* packet = Packet::decode(parse);
        if (packet != nullptr) {
            switch (packet->getType())
            {
                case 'P': {
                    // qDebug() << "PONG!";
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
                    emit speedChanged(((SpeedPacket*)packet)->left, ((SpeedPacket*)packet)->right);
                    break;
                
                case 'G':
                    emit gyroChanged(((GyroPacket*)packet)->x, ((GyroPacket*)packet)->y, ((GyroPacket*)packet)->z);
                    break;

                case 'A':
                    emit accelChanged(((AcceloPacket*)packet)->x, ((AcceloPacket*)packet)->y, ((AcceloPacket*)packet)->z);
                    break;

                case 'C':
                    emit closeConnection();
                    break;

                default:
                    qDebug() << "Undefined TCP packet  -->" <<  data.c_str();
                    break;
                
                delete packet;
            }
        } else return;
        separator = data.find(';');
        // qDebug() << "Znalazłem separator na miejscu: " << separator;
    }
}


/**
 * Prepare and send ping request
 */
void clientTCP::ping()
{
    qDebug() << "PING!";
    std::string data = PingPacket().prepare();
    qDebug() << data.c_str();
    socket->write(data.c_str(), data.size());
    this->lastPing = std::chrono::system_clock::now();
}

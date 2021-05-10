#ifndef TCP_H
#define TCP_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <chrono>
#include <ctime>  
#include "packet.hpp"

QT_BEGIN_NAMESPACE
class QTcpSocket;
QT_END_NAMESPACE


/*!
*   \file 
*   \brief The file contains the TCP client class.
*/


/**
    @brief TCP client connection class
*/
class clientTCP : public QObject
{
    Q_OBJECT
public:
    explicit clientTCP(QObject *parent = 0);
    void initConnection();
    QString address;
    int port;

    std::chrono::time_point<std::chrono::system_clock> lastPing = std::chrono::system_clock::now();

    QTcpSocket *socket;

signals:
    void latencyChanged(int latency);
    void batteryChanged(int level);
    void distanceChanged(int distance);
    void speedChanged(int left, int right);
    void gyroChanged(int x, int y, int z);
    void accelChanged(int x, int y, int z);
    void closeConnection();

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void ping();

private:
    QTimer timer;
};

#endif // TCP_H
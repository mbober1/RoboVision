#ifndef UDP_H
#define UDP_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include "packet.hpp"

QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE


/*!
*   \file 
*   \brief The file contains the UDP client class.
*/


/**
    @brief UDP client connection class
*/
class clientUDP : public QObject
{
    Q_OBJECT
public:
    QString address;
    int port;
    explicit clientUDP(QObject *parent = 0);
    QHostAddress client;
    void send(int left, int right);
    QUdpSocket *socket;
    void init();
    void close();

signals:
    
public slots:
    void connected();
    void disconnected();
    void readyRead();

private:
};

#endif // UDP_H
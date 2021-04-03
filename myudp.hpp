#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>

QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE

class clientUDP : public QObject
{
    Q_OBJECT
public:
    explicit clientUDP(QObject *parent = 0);
    QHostAddress client;
    void send(int left, int right);
    QUdpSocket *socket;
    void init(QString addr, int port);
    void close();

signals:
    
public slots:
    void connected();
    void disconnected();
    void readyRead();

private:
};

#endif // MYUDP_H
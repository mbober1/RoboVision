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
signals:
    
public slots:
    void readyRead();

private:
    QUdpSocket *socket;
};

#endif // MYUDP_H
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamepadmonitor.h"
#include "myudp.hpp"
#include "mytcp.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void leftX(double value);
    void leftY(double value);
    void gamepadStatus(bool status);
    void connectionError(QAbstractSocket::SocketError error);

    GamepadMonitor joystick;
    clientUDP udp;
    clientTCP tcp;

public slots:
    void on_pushButtonConnect_clicked();
    void changeConnectionStatus(QAbstractSocket::SocketState status);

private:
    QTimer dataTimer;
    Ui::MainWindow *ui;
    void readData();
    void toggleDataTimer();
};
#endif // MAINWINDOW_H

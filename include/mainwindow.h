#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "gamepadmonitor.h"
#include "myudp.hpp"
#include "mytcp.hpp"
#include "chart.hpp"
#include "scene.hpp"
// #include "keyboard.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


/**
    @brief Main window class
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connectionError(QAbstractSocket::SocketError error);

    GamepadMonitor joystick;
    // Keyboard keyboard;
    clientUDP udp;
    clientTCP tcp;
    Chart *chart = new Chart();
    Scene *scene = new Scene();

protected:
    void keyPressEvent(QKeyEvent* event);

public slots:
    void actionConnect();
    void actionDisconnect();
    void changeConnectionStatus(QAbstractSocket::SocketState status);

private:
    QTimer dataTimer;
    Ui::MainWindow *ui;
    void readData();
    void toggleDataTimer();
};
#endif // MAINWINDOW_H

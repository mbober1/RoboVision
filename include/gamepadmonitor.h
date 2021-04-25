#ifndef GAMEPADMONITOR_H
#define GAMEPADMONITOR_H

#include <QtCore/QObject>
#include <QtGamepad/QGamepad>

#include <QDebug>
#include <QLoggingCategory>

QT_BEGIN_NAMESPACE
class QGamepad;
QT_END_NAMESPACE


/**
    @brief Joystick class
*/
class GamepadMonitor : public QObject
{
    Q_OBJECT
public:
    explicit GamepadMonitor(QObject *parent = 0);
    ~GamepadMonitor();
    QGamepad *m_gamepad;

private:

};

#endif // GAMEPADMONITOR_H

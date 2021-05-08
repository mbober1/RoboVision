#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <QtCore/QObject>
#include <QtGamepad/QGamepad>

#include <QDebug>

QT_BEGIN_NAMESPACE
class QGamepad;
QT_END_NAMESPACE


/**
    @brief Joystick class
*/
class Gamepad : public QObject
{
    Q_OBJECT
public:
    explicit Gamepad(QObject *parent = 0);
    ~Gamepad();
    QGamepad *m_gamepad;

private:

};

#endif // GAMEPAD_H

#include "gamepadmonitor.h"


/**
 * A constructor.
 * @param parent QWidget type parent.
 */
GamepadMonitor::GamepadMonitor(QObject *parent)
    : QObject(parent)
    , m_gamepad(0)
{
    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    if (gamepads.isEmpty()) {
        qDebug() << "Did not find any connected gamepads";
        return;
    }

    m_gamepad = new QGamepad(*gamepads.begin(), this);
}


/**
 * A destructor.
 */
GamepadMonitor::~GamepadMonitor()
{
    delete m_gamepad;
}

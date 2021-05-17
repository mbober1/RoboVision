#include "gamepad.hpp"


/**
 * A constructor.
 * @param[in,out] parent QWidget type parent.
 */
Gamepad::Gamepad(QObject *parent)
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
Gamepad::~Gamepad()
{
    delete m_gamepad;
}

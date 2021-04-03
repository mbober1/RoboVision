#include "gamepadmonitor.h"


GamepadMonitor::GamepadMonitor(QObject *parent)
    : QObject(parent)
    , m_gamepad(0)
{
    
    // QLoggingCategory::setFilterRules(QStringLiteral("qt.gamepad.debug=true"));

    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    if (gamepads.isEmpty()) {
        qDebug() << "Did not find any connected gamepads";
        return;
    }

    m_gamepad = new QGamepad(*gamepads.begin(), this);
}

GamepadMonitor::~GamepadMonitor()
{
    delete m_gamepad;
}

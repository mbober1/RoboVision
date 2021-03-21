#include "gamepadmonitor.h"


GamepadMonitor::GamepadMonitor(QObject *parent)
    : QObject(parent)
    , m_gamepad(0)
{
    QLoggingCategory::setFilterRules(QStringLiteral("qt.gamepad.debug=true"));

    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    if (gamepads.isEmpty()) {
        qDebug() << "Did not find any connected gamepads";
        return;
    }

    m_gamepad = new QGamepad(*gamepads.begin(), this);

    connect(m_gamepad, &QGamepad::buttonAChanged, this, [](bool pressed){
        qDebug() << "Button A" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonBChanged, this, [](bool pressed){
        qDebug() << "Button B" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonXChanged, this, [](bool pressed){
        qDebug() << "Button X" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonYChanged, this, [](bool pressed){
        qDebug() << "Button Y" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonL1Changed, this, [](bool pressed){
        qDebug() << "Button L1" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonR1Changed, this, [](bool pressed){
        qDebug() << "Button R1" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonL2Changed, this, [](double value){
        qDebug() << "Button L2: " << value;
    });
    connect(m_gamepad, &QGamepad::buttonR2Changed, this, [](double value){
        qDebug() << "Button R2: " << value;
    });
    connect(m_gamepad, &QGamepad::buttonSelectChanged, this, [](bool pressed){
        qDebug() << "Button Select" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonStartChanged, this, [](bool pressed){
        qDebug() << "Button Start" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonGuideChanged, this, [](bool pressed){
        qDebug() << "Button Guide" << pressed;
    });
}

GamepadMonitor::~GamepadMonitor()
{
    delete m_gamepad;
}

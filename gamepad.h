#include <QObject>
#include <QtCore/QTimer>

class QGamepad;

class Gamepad2 : public QObject
{
    Q_OBJECT
public:
    explicit Gamepad2(QObject *parent = 0);
    ~Gamepad2();

private:
    QGamepad *m_gamepad;
};


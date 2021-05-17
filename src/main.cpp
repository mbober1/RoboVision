#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QResource::registerResource("/home/mbober/Documents/RoboVision/resources.rcc");
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    return app.exec();
}

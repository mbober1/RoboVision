#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    //         case 'X':
    //             x = -(std::stof(parse));
    //             printf("Gyroscope X: %.3f\n", x);
    //             break;
            
    //         case 'Y':
    //             y = -(std::stof(parse));
    //             printf("Gyroscope Y: %.3f\n", y);
    //             break;
            
    //         case 'Z':
    //             printf("Gyroscope Z: %s\n", parse.c_str());
    //             break;
            
    //         case 'B':
    //             printf("Battery voltage: %s\n", parse.c_str());
    //             break;
            
    //         default:
    //             printf("Unkown data: %s\n", parse.c_str());
    //             break;
    //        
    
    return app.exec();
}

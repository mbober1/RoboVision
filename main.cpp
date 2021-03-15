#include "mainwindow.h"
// #include "gamepad.h"
#include <QApplication>

#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>

std::string IP_ADDRES;
uint16_t PORT;
std::string STATUS;

#define PORT 8090
#define MAX_INT 64500
#define SENSITIVITY 6700
char recvBuf[100];
char sendBuf[100];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // Gamepad2 gamepadds;
    w.show();

    // int result;
    // int newSocket;

    // struct sockaddr_in server = {};
    // server.sin_family = AF_INET;
    // server.sin_port = htons(PORT);
    // server.sin_addr.s_addr = inet_addr("0.0.0.0");

    // struct sockaddr_in client = {};
    // client.sin_family = AF_INET;
    // client.sin_port = htons(PORT);
    // client.sin_addr.s_addr = inet_addr(IP_ADDRES.c_str());

    // newSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); 
   
    // socklen_t len = sizeof(server);
   
    // if(bind(newSocket, (struct sockaddr*) &server, len ) < 0 ) {
    //     perror("bind() ERROR");
    //     return 3;
    // }
    
    // float left, right, x, y;
    // int messLength;

    // while( 1 )
    // {
    //     if(recvfrom(newSocket, recvBuf, sizeof(recvBuf), 0,(struct sockaddr*)&server, &len) < 0) {
    //         perror("recvfrom() ERROR");
    //         return 4;
    //     } else {
    //         std::system("clear");
    //         printf("%s \n", recvBuf);
    //     }

    //     std::string data(recvBuf);

    //     while (!data.empty())
    //     {
    //         int separator = data.find(';');
    //         std::string parse = data.substr(1, separator - 1); 

    //         switch (data.front())
    //         {
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
    //         }
    //         if(separator == -1) data.clear();
    //         else data.erase(data.begin(), data.begin() + separator + 1);

    //     }
    //     left = (x - y) * SENSITIVITY;
    //     right = (x + y) * SENSITIVITY;
    //     if(left >  MAX_INT) left = MAX_INT;
    //     if(right > MAX_INT) right = MAX_INT;
    //     if(left < -MAX_INT) left = -MAX_INT;
    //     if(right < -MAX_INT) right = -MAX_INT;
    //     messLength = sprintf(sendBuf, "L%.0f;R%.0f", right, left);
    //     result = sendto(newSocket, sendBuf, messLength, 0, (struct sockaddr *) & client, sizeof(client));
    //     printf("Sent bytes: %d, %s\n", result, sendBuf);
    //     printf("L:%+3.0f% R:%+3.0f%\n", (left*10)/SENSITIVITY, (right*10)/SENSITIVITY);
    // }
    
    return a.exec();
}

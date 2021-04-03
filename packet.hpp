#ifndef MYPACKET_H
#define MYPACKET_H

#include <string>
#include "crc.h"
#include <QtCore/QtDebug>

class Packet {
public:
    Packet();
    Packet(std::string data);
    virtual const char* prepare() = 0;
    static Packet* decode(std::string data);
    virtual char getType() = 0;
};
#endif // MYPACKET_H

#ifndef MYPACKETPING_H
#define MYPACKETPING_H

class PingPacket : public Packet {
public:
    PingPacket();
    virtual const char* prepare();
    virtual char getType();
};

#endif // MYPACKET_H


#ifndef MYPACKETENGINE_H
#define MYPACKETENGINE_H

class EnginePacket : public Packet {
public:
    EnginePacket(std::string data);
    EnginePacket(int8_t left, int8_t right);
    virtual const char* prepare();
    int left;
    int right;
    virtual char getType();
};

#endif // MYPACKET_H

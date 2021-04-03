#include <string>
#include "crc.h"

class Packet {
    virtual std::string prepare() = 0;
public:
    Packet();
    Packet(std::string data);
    char type;
    int checksum;
};

class PingPacket : Packet {
    virtual std::string prepare() = 0;
public:
    char type = 'P';
};

class EnginePacket : Packet {
    virtual std::string prepare() = 0;
public:
    char type = 'E';
    int left;
    int right;
};



std::string PingPacket::prepare() {
    std::string tmp;
    tmp += this->type;
    tmp += ";";
    tmp += CRC::Calculate(tmp.c_str(), tmp.size(), CRC::CRC_32());
    return tmp;
}


std::string EnginePacket::prepare() {
    std::string tmp;
    tmp += this->type;
    tmp += this->left;
    tmp += " ";
    tmp += this->right;
    tmp += ";";
    tmp += CRC::Calculate(tmp.c_str(), tmp.size(), CRC::CRC_32());
    return tmp;
}
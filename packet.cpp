#include "packet.hpp"

Packet::Packet() {}

Packet* Packet::decode(std::string data) {
    char type = data.at(0);
    switch (type)
    {
    case 'P':
        return new PingPacket();

    case 'E':
        return new EnginePacket(data);
    
    default:
        return nullptr;
        // qDebug() << "unknown packet";
        break;
    }
}

PingPacket::PingPacket() {}

const char* PingPacket::prepare() {
    std::string tmp;
    tmp += this->getType();
    tmp += ';';
    tmp += CRC::Calculate(tmp.c_str(), tmp.size(), CRC::CRC_32());
    return tmp.c_str();
}

char PingPacket::getType() {
    return 'P';
}

// E12 3;C
EnginePacket::EnginePacket(std::string data)
{
    this->left = (int8_t)(data[1]);
    this->right = (int8_t)(data[3]);
}

char EnginePacket::getType() {
    return 'E';
}

EnginePacket::EnginePacket(int8_t left, int8_t right)
    : left(left),
      right(right)
{
    
}

const char* EnginePacket::prepare() {
    std::string tmp;
    tmp += this->getType();
    tmp += this->left;
    tmp += ' ';
    tmp += this->right;
    tmp += ';';
    tmp += CRC::Calculate(tmp.c_str(), tmp.size(), CRC::CRC_32());
    return tmp.c_str();
}
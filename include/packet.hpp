#pragma once
#include <string>
#include "crc.h"


/*!
*   \file 
*   \brief The file contains the package class definitions and derived classes.
*/

/**
    @brief Generic packet class
*/
class Packet {
public:
    Packet();
    Packet(const std::string &data);
    virtual ~Packet() = 0;
    virtual std::string prepare() = 0;
    static Packet* decode(std::string &data);
    virtual char getType() = 0;
    static uint8_t checksum(const std::string &data);
};


/**
    @brief Ping request class
*/
class PingPacket : public Packet {
public:
    PingPacket();
    ~PingPacket();
    virtual std::string prepare();
    virtual char getType();
};


/**
    @brief Engine power management class
*/
class EnginePacket : public Packet {
public:
    EnginePacket(const std::string &data);
    EnginePacket(const int8_t &left, const int8_t &right);
    EnginePacket();
    ~EnginePacket();
    virtual std::string prepare();
    int left;
    int right;
    virtual char getType();
};


/**
    @brief Battery power management class
*/
class BatteryPacket : public Packet {
public:
    BatteryPacket(const std::string &data);
    BatteryPacket(const uint8_t &level);
    ~BatteryPacket();
    virtual std::string prepare();
    int level;
    virtual char getType();
};


/**
    @brief Obstalce distance management class
*/
class DistancePacket : public Packet {
public:
    DistancePacket(const std::string &data);
    DistancePacket(const uint8_t &distance);
    ~DistancePacket();
    virtual std::string prepare();
    int distance;
    virtual char getType();
};


/**
    @brief Engine speed management class
*/
class SpeedPacket : public Packet {
public:
    SpeedPacket(const std::string &data);
    SpeedPacket(const int8_t &left, const int8_t &right);
    ~SpeedPacket();
    virtual std::string prepare();
    int8_t left;
    int8_t right;
    virtual char getType();
};


/**
    @brief Connection status management class
*/
class ClosePacket : public Packet {
public:
    ClosePacket();
    ~ClosePacket();
    virtual std::string prepare();
    virtual char getType();
};


/**
    @brief Accelometer data management class
*/
class AcceloPacket : public Packet {
public:
    AcceloPacket(std::string data);
    AcceloPacket(const int8_t &x, const int8_t &y, const int8_t &z);
    AcceloPacket();
    ~AcceloPacket();
    virtual std::string prepare();
    int8_t x, y, z;
    virtual char getType();
};


/**
    @brief Gyroscop data management class
*/
class GyroPacket : public Packet {
public:
    GyroPacket(std::string data);
    GyroPacket(const int8_t &x, const int8_t &y, const int8_t &z);
    GyroPacket();
    ~GyroPacket();
    virtual std::string prepare();
    int8_t x, y, z;
    virtual char getType();
};
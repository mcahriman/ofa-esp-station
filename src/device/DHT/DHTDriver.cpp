#include <Arduino.h>
#include "DHTDriver.hpp"

#include "device/BaseCapability.hpp"


DHTDriver::DHTDriver(String name, uint8_t pin, SensorType sensorType)
{
    driverName = name;

    initDHTDevice(pin, sensorType);

    //todo: make base class maybe?
    registerCallbacks();
    registerCapabilities();
}

void DHTDriver::registerCallbacks()
{
    driverOnlineDelegate = [this]() {
        return this->isOnline();
    };

    humidityDelegate = [dhtDevice = dhtDevice]() {
        return String(dhtDevice->readHumidity());
    };

    temperatureDelegate = [dhtDevice = dhtDevice]() {
        return String(dhtDevice->readTemperature());
    };
}

void DHTDriver::registerCapabilities()
{
    capabilities.registerCapability(new BaseCapability("DHT_T", temperatureDelegate, driverOnlineDelegate));
    capabilities.registerCapability(new BaseCapability("DHT_H", humidityDelegate, driverOnlineDelegate));
}

bool DHTDriver::isOnline()
{
    return dhtDevice != nullptr && dhtDevice->readTemperature() != NAN;
}

String DHTDriver::getName()
{
    return driverName;
}

void DHTDriver::initDHTDevice(uint8_t pin, SensorType sensorType)
{

    uint8_t dhtType;
    switch (sensorType)
    {
    case SensorType::DHT_11:
        dhtType = DHT11;
        break;

    default:
        dhtType = DHT22;
        break;
    }

    dhtDevice = make_shared<DHT>(pin, dhtType);
    dhtDevice->begin();
}

DHTDriver::~DHTDriver() {
}
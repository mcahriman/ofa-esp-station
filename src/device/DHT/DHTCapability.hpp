#pragma once

#include <Arduino.h>
#include <device/ICapability.hpp>
#include <DHT.h>

#define DHT_DEFAULT_NAME "DHT"
#define DHT_DEFAULT_PIN 5

enum class SensorType {DHT_11,DHT_22};
enum class SensorValueType { DHT_TEMP, DHT_HUMIDITY};

/**
 * DHT Capability: for DHT Sensor
 * 
 * add dht11 support
 */
class DHTCapability : public ICapability
{
  public:

    DHTCapability(String name, SensorValueType value_type,  SensorType sensor_type = SensorType::DHT_22, int pin = DHT_DEFAULT_PIN);

    String getName();
    String getValue();
    bool isValid();

  private:
    //TODO:
    static DHT *dht_22_sensor;
    static DHT *dht_11_sensor;
    String capabilityName;
    SensorValueType valueType;
    SensorType sensorType;
};
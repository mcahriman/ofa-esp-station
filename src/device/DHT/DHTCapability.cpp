#include "DHTCapability.hpp"
#include "Arduino.h"

DHT *DHTCapability::dht_22_sensor = NULL;
DHT *DHTCapability::dht_11_sensor = NULL;

DHTCapability::DHTCapability(String name, SensorValueType value_type, SensorType sensor_type, int pin ) {
    if (sensor_type == SensorType::DHT_22 && dht_22_sensor == NULL)
    {
        dht_22_sensor = new DHT(pin, DHT22);
        dht_22_sensor->begin();
    }
    else if (sensor_type == SensorType::DHT_22 && dht_11_sensor == NULL)
    {
        dht_11_sensor = new DHT(pin, DHT11);
        dht_11_sensor->begin();
    }
    capabilityName = name;
    sensorType = sensor_type;
    valueType
     = value_type;
    Serial.println("Initialized dht sensor with name" + name);
}

String DHTCapability::getValue()
{
    DHT *device;

    char buf[6];
    //kill me pls
    if (sensorType ==  SensorType::DHT_22) {
        device = dht_22_sensor;
    } else {
        device = dht_11_sensor;
    }

    if (device == NULL)
    {
        return "n/a";
    }
    else
    {
        if (valueType == SensorValueType::DHT_HUMIDITY)
        {
            return String(device->readHumidity());
        } else {
            return String(device->readTemperature());
        }
    }
    return String(buf);
}
bool DHTCapability::isValid()
{
    //research validation
    return true;
}

String DHTCapability::getName() {
    return capabilityName;
}
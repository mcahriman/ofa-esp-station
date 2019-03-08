#pragma once

#include <Arduino.h>
#include <DHT.h>

#include "device/IDriver.hpp"

const uint8_t default_pin = 5;

enum class SensorType
{
  DHT_11,
  DHT_22
};

class DHTDriver : public IDriver
{
public:
  DHTDriver(String, uint8_t pin = default_pin, SensorType SensorType = SensorType::DHT_22);
  ~DHTDriver();

  CapabilityRegistry &getCapabilities() { return capabilities; }
  String getName();
  bool isOnline();

private:
  shared_ptr<DHT> dhtDevice;
  String driverName = "DHTDriver";
  CapabilityRegistry capabilities;

  std::function<bool()> driverOnlineDelegate;
  std::function<String()> humidityDelegate;
  std::function<String()> temperatureDelegate;

  void initDHTDevice(uint8_t, SensorType);
  void registerCallbacks();
  void registerCapabilities();
};
#pragma once

#include <Arduino.h>

#include "device/IDriver.hpp"
#include "device/CapabilityRegistry.hpp"

class SampleDriver : public IDriver
{
 public:
   SampleDriver(String);
   CapabilityRegistry& getCapabilities() { return capabilities;}
   String getName();
   bool isOnline();

 private:
   void doSomeSampleMagic();
   String capabilityName = "SampleCapabilityDefault";
   String getValue();
   String deviceName;
   CapabilityRegistry capabilities;
   std::function<bool()> driverOnlineDelegate;
   std::function<String()> getWoofValueDelegate;
};
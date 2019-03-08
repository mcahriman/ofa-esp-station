#pragma once

#include <Arduino.h>

#include "device/IDriver.hpp"
#include "device/CapabilityRegistry.hpp"

class SampleDriver : public IDriver
{
 public:
   SampleDriver(String);
   ~SampleDriver() {};
   CapabilityRegistry& getCapabilities() { return capabilities;}
   String getName();
   bool isOnline();

 private:
   void doSomeSampleMagic();
   String driverName = "SampleDriverDefault";
   String getSomeValue();
   String getSomeAnotherValue();
   String deviceName;
   CapabilityRegistry capabilities;
   
   std::function<bool()> driverOnlineDelegate;
   std::function<String()> getWoofValueDelegate;
   std::function<String()> getKtulhuFhtagnDelegate;
};
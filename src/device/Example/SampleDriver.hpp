#pragma once

#include "device/IDriver.hpp"
#include "device/CapabilityRegistry.hpp"

class SampleDriver : public IDriver
{
 public:
   SampleDriver(string);
   CapabilityRegistry& getCapabilities() { return capabilities;}
   string getName();
   bool isOnline();

 private:
   void doSomeSampleMagic();
   string capabilityName = "SampleCapabilityDefault";
   string getValue();
   string deviceName;
   CapabilityRegistry capabilities;
   std::function<bool()> driverOnlineDelegate;
   std::function<string()> getWoofValueDelegate;
};
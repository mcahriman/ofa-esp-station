#pragma once

#include <Arduino.h>

#include "device/ICapability.hpp"

class BaseCapability : public ICapability
{
public:
  BaseCapability(String name, std::function<String()>, std::function<bool()>, ICapabilityType type = ICapabilityType::CAP_VALUE);
  virtual String getName();
  virtual String getValue();
  virtual bool isOnline();
  ICapabilityType getCapabilityType();
protected:
  String name;
  std::function<String()> valueDelegate;
  ICapabilityType capabilityType;
  std::function<boolean()> onlineDelegate;
};
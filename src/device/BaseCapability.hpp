#pragma once

#include <Arduino.h>

#include "device/ICapability.hpp"

class BaseCapability : public ICapability
{
public:
  BaseCapability(String name, std::function<String()>, std::function<bool()>);
  virtual String getName();
  virtual String getValue();
  virtual bool isOnline();

protected:
  String name;
  std::function<String()> valueDelegate;
  std::function<boolean()> onlineDelegate;
};
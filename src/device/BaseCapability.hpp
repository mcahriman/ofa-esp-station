#pragma once
#include <string>

#include "device/ICapability.hpp"
#include <functional>

class BaseCapability : public ICapability
{
public:
  BaseCapability(string name, std::function<string()>, std::function<bool()>);
  virtual string getName();
  virtual string getValue();
  virtual bool isOnline();

protected:
  string name;
  std::function<string()> valueDelegate;
  std::function<bool()> onlineDelegate;
};
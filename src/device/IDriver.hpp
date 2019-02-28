#pragma once

#include <list>
#include <string>
#include "ICapability.hpp"
#include "CapabilityRegistry.hpp"

using namespace std;

class IDriver
{
  public:
    virtual CapabilityRegistry& getCapabilities() = 0;
    virtual string getName() = 0;
    virtual bool isOnline() = 0;
};
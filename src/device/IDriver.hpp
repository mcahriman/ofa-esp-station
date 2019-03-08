#pragma once

#include <list>
#include "ICapability.hpp"
#include "CapabilityRegistry.hpp"

class IDriver
{
  public:
    virtual ~IDriver() {};
    virtual CapabilityRegistry& getCapabilities() = 0;
    virtual String getName() = 0;
    virtual bool isOnline() = 0;
};
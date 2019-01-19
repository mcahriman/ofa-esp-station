#pragma once

#include <Arduino.h>

#include "ICapability.hpp"

class SampleCapability : public ICapability
{
  public:
       SampleCapability();
       SampleCapability(String);
       String getName();
       String getValue();
       bool isValid() {
          return true;
       }

    private:
       void doSomeSampleMagic();
       String capabilityName = "SampleCapabilityDefault";
};
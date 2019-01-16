#include <Arduino.h>

#include "ICapability.hpp"

class SampleCapability : public ICapability
{
  public:
       SampleCapability();
       SampleCapability(String);
       String getName();
       String getValue();

    private:
       void doSomeSampleMagic();
       String capabilityName = "SampleCapabilityDefault";
};
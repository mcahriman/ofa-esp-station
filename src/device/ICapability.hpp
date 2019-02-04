#pragma once

//TODO: get rid of arduino in api
#include <Arduino.h>

enum class ICapabilityType {
    CAP_INTERNAL,
    CAP_VALUE
};

class ICapability {
    public:
       virtual String getName() = 0;
       virtual String getValue() = 0;
       virtual bool isOnline() = 0;
       virtual ICapabilityType getCapabilityType() { return ICapabilityType::CAP_VALUE; };
};
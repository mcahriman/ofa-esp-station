#pragma once

#include <Arduino.h>

class ICapability {
    public:
       virtual String getName() = 0;
       virtual String getValue() = 0;
};
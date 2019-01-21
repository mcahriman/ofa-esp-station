#pragma once

#include <Arduino.h>
#include "ICapability.hpp"
#include <list>
#include <utility>

using namespace std;

class CapabilityRegistry : public std::list<ICapability*> {
    public:
        CapabilityRegistry();
        list<std::pair<String,String>> getAllReadings();
        list<String> listCapabilities();
};

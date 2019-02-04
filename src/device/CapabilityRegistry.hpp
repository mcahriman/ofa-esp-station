#pragma once

#include <Arduino.h>
#include "ICapability.hpp"
#include <list>
#include <utility>
#include <memory>

using namespace std;

class CapabilityRegistry : public list<unique_ptr<ICapability>> {
    public:
        list<std::pair<String,String>> getAllReadings();
        list<String> listCapabilities();
};

#pragma once

#include <Arduino.h>
#include "ICapability.hpp"
#include <list>
#include <utility>
#include <memory>

using namespace std;

class CapabilityRegistry {
    public:
        list<std::pair<String,String>> getAllReadings();
        list<String> listCapabilities();
        void registerCapability( ICapability *);

    private:
        list<shared_ptr<ICapability>> capabilities;
};

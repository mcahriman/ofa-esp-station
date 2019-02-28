#pragma once

#include <string>
#include "ICapability.hpp"
#include <list>
#include <utility>
#include <memory>

using namespace std;

class CapabilityRegistry : public list<unique_ptr<ICapability>> {
    public:
        list<std::pair<string,string>> getAllReadings();
        list<string> listCapabilities();
};

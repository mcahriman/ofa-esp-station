#pragma once
#include <string>

using namespace std;

enum class ICapabilityType {
    CAP_INTERNAL,
    CAP_VALUE
};

class ICapability {
    public:
       virtual string getName() = 0;
       virtual string getValue() = 0;
       virtual bool isOnline() = 0;
       virtual ICapabilityType getCapabilityType() { return ICapabilityType::CAP_VALUE; };
};
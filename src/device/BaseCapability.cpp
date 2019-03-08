#include "BaseCapability.hpp"
#include <Arduino.h>

BaseCapability::BaseCapability(String capName,
                               std::function<String()> valueFunc,
                               std::function<bool()> onlineFunc,
                               ICapabilityType type)
{
    valueDelegate = valueFunc;
    onlineDelegate = onlineFunc;
    name = capName;
    this->capabilityType = type;
}

String BaseCapability::getName()
{
    return name;
}

String BaseCapability::getValue()
{
    return valueDelegate();
}

bool BaseCapability::isOnline()
{
    return onlineDelegate();
}

ICapabilityType BaseCapability::getCapabilityType() {
    return capabilityType;
}
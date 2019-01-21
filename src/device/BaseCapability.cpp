#include "BaseCapability.hpp"
#include <Arduino.h>

BaseCapability::BaseCapability(String name, std::function<String()> valueFunc, std::function<bool()> onlineFunc) {
    valueDelegate = valueFunc;
    onlineDelegate = onlineFunc;
}

String BaseCapability::getName() {
    return name;
}

String BaseCapability::getValue() {
    return valueDelegate();
}

bool BaseCapability::isOnline() {
    return onlineDelegate();
}
#include "BaseCapability.hpp"
#include <functional>

BaseCapability::BaseCapability(string name, std::function<string()> valueFunc, std::function<bool()> onlineFunc) {
    valueDelegate = valueFunc;
    onlineDelegate = onlineFunc;
}

string BaseCapability::getName() {
    return name;
}

string BaseCapability::getValue() {
    return valueDelegate();
}

bool BaseCapability::isOnline() {
    return onlineDelegate();
}
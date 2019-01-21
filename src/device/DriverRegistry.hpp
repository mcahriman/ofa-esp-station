#pragma once

#include <list>
#include "IDriver.hpp"

class DriverRegistry : public std::list<IDriver> {
    public:
        DriverRegistry();
};
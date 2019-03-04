#pragma once

#include "device/DriverRegistry.hpp"
#include "BaseLogger.hpp"

class System {
    public:
        System();

        void setLogger(BaseLogger*);
        void startUp();

    private:
        shared_ptr<DriverRegistry> driverRegistry;

        BaseLogger* logger;
};
#pragma once

#include "device/DriverRegistry.hpp"
#include "BaseLogger.hpp"

enum class SystemHealthStatus {
    STARTING_UP,
    HEALTHY,
    UNHEALTHY,
    UNSTABLE
};

class System {
    public:
        System();

        void setLogger(BaseLogger*);
        void startUp();
        SystemHealthStatus healthCheck();

    private:
        shared_ptr<DriverRegistry> driverRegistry;
        BaseLogger* logger;
};
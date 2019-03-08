#pragma once

#include "device/DriverRegistry.hpp"
#include "BaseLogger.hpp"

//TODO: remove when spifs configuration is ready 

#ifndef AP_NAME
#define AP_NAME "amstestharness"
#endif

#ifndef AP_PASSWD
#define AP_PASSWD "letschecksensors"
#endif // !AP_PASSWD


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

        String getDriverReadingsJson(ICapabilityType);
};
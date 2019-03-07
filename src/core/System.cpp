#include "System.hpp"

#include "device/DHT/DHTDriver.hpp"
#include "device/Example/SampleDriver.hpp"

#include "util/Utils.hpp"

//TODO: Register drivers by DriverResolver (TBD)
//Consider driver initialization as hardcoded stuff


System::System() {
    driverRegistry = make_shared<DriverRegistry>();
}

void System::setLogger(BaseLogger* logger) {
    this->logger = logger;
}

void System::startUp() {
    logger->Log(LogLevel::INFO, "System startup sequence initialized lol");
    // check mode (configuration or work)
    // here say if it is ok

    logger->Log(LogLevel::TRACE,"Adding DHT22 Driver");
    driverRegistry->push_back(new DHTDriver("DHT22"));

    logger->Log(LogLevel::TRACE, "Sample driver");
    driverRegistry->push_back(new SampleDriver("HelloWorld"));


}

SystemHealthStatus System::healthCheck() {
    
    logger->Log(LogLevel::TRACE, "System seems to be healthy");

    list<pair<String,String>> readings;


    logger->Log(LogLevel::TRACE, "Try getting drv readings");
    //get flat reading list
    for(auto drvIter = driverRegistry->begin(); drvIter != driverRegistry->end(); drvIter++ ) {
        auto drvReadings = (*drvIter)->getCapabilities().getAllReadings();
        readings.insert(readings.end(), drvReadings.begin(), drvReadings.end());
    }
    logger->Log(LogLevel::TRACE, "finishing reading stuff");

    logger->Log(LogLevel::TRACE, utils_json_object(readings).c_str());

    return SystemHealthStatus::STARTING_UP;

}

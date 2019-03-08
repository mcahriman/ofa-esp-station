#include "System.hpp"

#include "device/DHT/DHTDriver.hpp"
#include "device/Example/SampleDriver.hpp"
#include "device/Wifi/WifiDriver.hpp"

#include "util/Utils.hpp"

//TODO: Register drivers by DriverResolver (TBD)
//Consider driver initialization as hardcoded stuff

System::System()
{
    driverRegistry = make_shared<DriverRegistry>();
}

void System::setLogger(BaseLogger *logger)
{
    this->logger = logger;
}

void System::startUp()
{
    logger->Log(LogLevel::INFO, "System startup sequence initialized lol");
    // check mode (configuration or work)
    // here say if it is ok

    logger->Log(LogLevel::TRACE, "Connecting to Wifi");
    WifiDriver *wifiDriver = new WifiDriver("ESPWifi");
    wifiDriver->setCredentials(AP_NAME, AP_PASSWD);
    wifiDriver->setSleepMode(WiFiSleepType_t::WIFI_LIGHT_SLEEP);
    wifiDriver->connect();

    driverRegistry->push_back(wifiDriver);

    logger->Log(LogLevel::TRACE, "Adding DHT22 Driver");
    driverRegistry->push_back(new DHTDriver("DHT22"));

    logger->Log(LogLevel::TRACE, "Sample driver");
    driverRegistry->push_back(new SampleDriver("HelloWorld"));
}

SystemHealthStatus System::healthCheck()
{

    logger->Log(LogLevel::TRACE, "System seems to be healthy");

    logger->Log(LogLevel::TRACE, "Internal readings");
    logger->Log(LogLevel::TRACE, getDriverReadingsJson(ICapabilityType::CAP_INTERNAL).c_str());

    logger->Log(LogLevel::TRACE, "Value readings");
    logger->Log(LogLevel::TRACE, getDriverReadingsJson(ICapabilityType::CAP_VALUE).c_str());


    return SystemHealthStatus::STARTING_UP;
}

String System::getDriverReadingsJson(ICapabilityType capabilityType)
{
    list<pair<String, String>> readings;

    for (auto drvIter = driverRegistry->begin(); drvIter != driverRegistry->end(); drvIter++)
    {
        auto drvReadings = (*drvIter)->getCapabilities().getReadingsByType(capabilityType);

        readings.insert(readings.end(), drvReadings.begin(), drvReadings.end());
    }
    return utils_json_object(readings);
}

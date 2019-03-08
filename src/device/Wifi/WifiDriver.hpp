#pragma once

#include "device/IDriver.hpp"
#include "ESP8266WiFi.h"
#include "core/StreamLogger.hpp"

#include "Arduino.h"

enum class WifiStatus {
    CONNECTED,
    DISCONNECTED
};

class WifiDriver : public IDriver
{
  public:

    WifiDriver(String); 
    ~WifiDriver() {};

    CapabilityRegistry& getCapabilities() { return capabilities; };
    bool isOnline();
    String getName();
    void setCredentials(String SSID, String Password);



    //check dependencies
    void setMode(WiFiMode_t);
    void setSleepMode(WiFiSleepType_t);
    void connect();
    WifiStatus getStatus();
    void setLogger(BaseLogger* logger);

    void reconnect();

  private:
    CapabilityRegistry capabilities;
    String name;
    BaseLogger* logger;

    String ssid;
    String passwd;

    std::function<bool()> isOnlineDelegate;
    std::function<String()> currentIpDelegate;
    std::function<String()> macAddrDelegate;

};
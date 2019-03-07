#pragma once

#include "device/IDriver.hpp"
#include "ESP8266WiFi.h"
#include "core/StreamLogger.hpp"

enum class WifiStatus {
    CONNECTED,
    DISCONNECTED
};

class WifiDriver : public IDriver
{
  public:
    WifiDriver();

    CapabilityRegistry &getCapabilities();
    bool isOnline();
    
    String getName()
    {
        return name;
    }

    void setCredentials(String SSID, String Password);

    //check dependencies
    void setMode(WiFiMode_t);
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
#include "WifiDriver.hpp"
#include "device/BaseCapability.hpp"

WifiDriver::WifiDriver(String)
{
    isOnlineDelegate = [this] {
        return this->isOnline();
    };
    currentIpDelegate = [] {
        return WiFi.localIP().toString();
    };

    macAddrDelegate = [] {
        return WiFi.macAddress();
    };

    this->name = "ESP8266WiFi";

    capabilities.registerCapability(
        new BaseCapability("ip_addr", currentIpDelegate, isOnlineDelegate, ICapabilityType::CAP_INTERNAL));
    capabilities.registerCapability(
        new BaseCapability("mac_addr", macAddrDelegate, isOnlineDelegate, ICapabilityType::CAP_INTERNAL));
}

bool WifiDriver::isOnline()
{
    return WiFi.isConnected();
}

String WifiDriver::getName()
{
    return name;
}

void WifiDriver::setCredentials(String ssid, String password)
{
    this->ssid = ssid;
    this->passwd = password;
}

void WifiDriver::setSleepMode(WiFiSleepType_t sleeptype)
{
    WiFi.setSleepMode(sleeptype);
}

void WifiDriver::connect()
{
    WiFi.begin(ssid.c_str(), passwd.c_str());
}

void WifiDriver::setLogger(BaseLogger *logger)
{
    this->logger = logger;
}

WifiStatus WifiDriver::getStatus()
{
    wl_status_t status = WiFi.status();
    switch (status)
    {
    case WL_CONNECTED:
        return WifiStatus::CONNECTED;
    case WL_CONNECT_FAILED:
    case WL_CONNECTION_LOST:
    default:
        return WifiStatus::DISCONNECTED;
    }
}

void WifiDriver::reconnect()
{
    WiFi.reconnect();
}
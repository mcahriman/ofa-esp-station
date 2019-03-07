#include "WifiDriver.hpp"
#include "device/BaseCapability.hpp"

WifiDriver::WifiDriver() {
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

    capabilities.registerCapability(new BaseCapability("ip_addr", currentIpDelegate, isOnlineDelegate));
    capabilities.registerCapability(new BaseCapability("mac_addr", macAddrDelegate, isOnlineDelegate));

}

bool WifiDriver::isOnline() {
    return WiFi.isConnected();
}

void WifiDriver::setCredentials(String ssid, String password) {
    this->ssid = ssid;
    this->passwd = password; 
}

void WifiDriver::connect() {
    WiFi.begin(ssid.c_str(), passwd.c_str());
}

void WifiDriver::setLogger(BaseLogger* logger) {
    this->logger = logger;
}

WifiStatus WifiDriver::getStatus() {
    wl_status_t status =  WiFi.status();
    switch (status)
    {
        case WL_CONNECTED:
            return WifiStatus::CONNECTED;
        case  WL_CONNECT_FAILED:
        case  WL_CONNECTION_LOST:
        default:
            return WifiStatus::DISCONNECTED;
    }
}

void WifiDriver::reconnect() {
    WiFi.reconnect();
}
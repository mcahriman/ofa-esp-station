#pragma once

#include <Arduino.h>

#include "device/IDriver.hpp"
#include "SoftwareSerial.h"
#include "device/ICapability.hpp"
#include "device/CapabilityRegistry.hpp"

#define MHZ14A_READ_CMD                 "\xFF\x01\x86\x00\x00\x00\x00\x00\x79"
#define MHZ14A_CALIBRATE_ZERO_POINT_CMD "\xFF\x01\x87\x00\x00\x00\x00\x00\x78"
#define MHZ14A_DEFAULT_NAME             "MHZ14A_CO2"
/**
 * MHZ14A Capability
 * Constructor takes tx and rx pins as 
 * 
 */

static const int default_rx = 14;
static const int default_tx = 12;

class MHZ14ADriver : public IDriver {
  public:
       MHZ14ADriver(int rx = default_rx, int tx = default_tx, String name = MHZ14A_DEFAULT_NAME);

       MHZ14ADriver(String name) {
           MHZ14ADriver(default_rx, default_tx, name);
       };

       ~MHZ14ADriver();

       bool isValid();
       String getName();
       String getValue();
       CapabilityRegistry& getCapabilities();
       bool isOnline();
       

    private:
       const int baud = 9600;
       const int cmd_len = 9;
       const int default_timeout = 50;

       char responseBuffer[9];
       String capabilityName = "MHZ14A_CO2";
       SoftwareSerial* serialPort;

       int read_value();
       void performReading();
       bool is_valid;
};
#include "MHZ14ADriver.hpp"
#include "Arduino.h"

MHZ14ADriver::MHZ14ADriver(int rx, int tx, String name) {
    memset(responseBuffer,0, 9);
    serialPort = new SoftwareSerial(rx, tx);
    serialPort->enableRx(true);
    serialPort->setTimeout(default_timeout);
    serialPort->begin(baud);
    performReading();
    
    if(responseBuffer[8] == 0) {
        is_valid = false;
        Serial.printf("Could not initialize MHZ Sensor on rx: %d tx: %d with response: %c\n", rx, tx,responseBuffer[8]);
    } else {
        Serial.printf("Initialised MHZ Sensor on rx: %d tx: %d with response: %c\n", rx, tx,responseBuffer[8]);
    }
    
    capabilityName = name;  
}

MHZ14ADriver::~MHZ14ADriver() {
    delete serialPort;
}

String MHZ14ADriver::getValue() 
{
    return isValid() ? String(read_value()) : "n/a";
}

int MHZ14ADriver::read_value() {
    performReading();
    return responseBuffer[2] * 256 + responseBuffer[3];
}

void MHZ14ADriver::performReading() {
    int read_qty = 0;
    serialPort->write(MHZ14A_READ_CMD, cmd_len);
    read_qty = serialPort->readBytes(responseBuffer,cmd_len);

    Serial.printf("Read %d bytes from MZH\n", read_qty);
}

bool MHZ14ADriver::isValid() {
    return is_valid;
}

String MHZ14ADriver::getName() {
    return capabilityName;
}
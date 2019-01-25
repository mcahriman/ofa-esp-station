#include "MHZ14ACapability.hpp"
#include "Arduino.h"

MHZ14ACapability::MHZ14ACapability(int rx, int tx, String name)
{
    memset(responseBuffer, 0, 9);
    serialPort = new SoftwareSerial(rx, tx);
    serialPort->enableRx(true);
    serialPort->setTimeout(default_timeout);
    serialPort->begin(baud);

    Serial.println("Initializing MHZ14A");
    is_valid = false;

    for (int tries = 0; tries < 8; tries++)
    {
        performReading();

        if (responseBuffer[8] == 0)
        {
            is_valid = false;
            Serial.print(".");
            delay(500);
        }
        else
        {
            Serial.printf("Initialized MHZ Sensor on rx: %d tx: %d with response: %c\n", rx, tx, responseBuffer[8]);
            is_valid = true;
            break;          
        }
    }
    if(is_valid == false) {
        Serial.println("Could not not initialize MHZ sensor");
    }

    capabilityName = name;
}

MHZ14ACapability::~MHZ14ACapability()
{
    delete serialPort;
}

String MHZ14ACapability::getValue()
{
    return isValid() ? String(read_value()) : "n/a";
}

int MHZ14ACapability::read_value()
{
    performReading();
    return responseBuffer[2] * 256 + responseBuffer[3];
}

void MHZ14ACapability::performReading()
{
    int read_qty = 0;
    serialPort->write(MHZ14A_READ_CMD, cmd_len);
    read_qty = serialPort->readBytes(responseBuffer, cmd_len);
}

bool MHZ14ACapability::isValid()
{
    return is_valid;
}

String MHZ14ACapability::getName()
{
    return capabilityName;
}
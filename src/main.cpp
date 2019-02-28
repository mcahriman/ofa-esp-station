#include <functional>
#include "device/Example/SampleDriver.hpp"

#include "espressif/esp_common.h"
#include "uart.h"

using namespace std;


extern "C"
void user_init(void) {
   UART_SetBaudrate(UART0, 115200);

}
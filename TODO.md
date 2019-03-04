# Todo list:
sorted by whatever

- Pools, Registries etc naming should become more consistant, need to get an idea for separation between driver and device
- System initialization: find convinient device initialization using the 3rd party configurations, and on-the-fly updates
- (Impl) filesystem and toolchain
- Unit tests!

# Versions

## 1.x (sealed)

- DHT, MZH sensors reading
- Warm DaaS Wifi endpoint, compiled in configuration

## 2.x (in dev) "derp-sleep":

- Cold deep sleeping mqtt client
- STA configuration with AP web-interface
    - configure wifi access point we are connection to
    - Adds choice for and mqtt endpoint if applicable 
- Add I2C bus with predefined set of devices
- Did I say deep sleep?
- new set of devices:
  - CC8025
  - DHT_WHATEVER
  - built in ADC
  - BME/P280

## 3.x (planned) "scope-crêpe"

- Connected devices are configured in arbitrary way
  - fetch driverParameters;
  - instantiate devices based on driverParameters configuration (pins, etc)
  - configurable derp sleep?
- JSON Schema support for all json fans
- Technical stuff
  - mitigate heap fragmentation issues
  - finally stabilize naming convention and API


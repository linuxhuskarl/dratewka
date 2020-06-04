# ESP32 Firmware Project

We fight __smog__. We are doing it right.

This is an ESP32 firmware project. It is a part of a bigger group project:
**Dratewka**, which aims to provide cheap air quality sensor network, able to
measure:

- PM1, PM2.5, PM10 particulate concentration
- Carbon monoxide and benzene concentration
- Atmospheric pressure, temperature and relative humidity

Espressif ESP32 is a wireless conectivity module, with onboard dual-core
microcontroller. It is highly configurabille and has numerous low-power modes.

This project is developed using Platform IO - a new generation toolset for
embedded C/C++ development. Intelligent code completion and Smart code linter
with Built-in Terminal and Serial Port Monitor. Contrary to Arduino IDE, it is
tailored for professional team use, with automatic library management and
project structure prepared with source-code versioning software in mind.

This project uses following libraries:

- PMSerial
- Adafruit BME280 Library
- PubSubClient
- ArduinoJson

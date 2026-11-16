# Task 04 — SD Card Data Logger: Connections

Board: VEGA ARIES v3. Module: MicroSD card module using SPI.

| Module signal | Board connection |
|---|---|
| CS / chip select | D10 (from `chipSelect = 10` in the supplied sketch) |
| SCK | Board hardware SPI SCK |
| MOSI | Board hardware SPI MOSI |
| MISO | Board hardware SPI MISO |
| VCC | Module-rated supply; check the module specification |
| GND | Common GND |

The supplied sketch calls `SD.begin(10)` and includes `SPI.h`. The ZIP does not specify the ARIES v3 hardware SPI pin numbers for SCK/MOSI/MISO, so use the board's official pin map rather than guessing. The report records SD initialization as not yet verified.
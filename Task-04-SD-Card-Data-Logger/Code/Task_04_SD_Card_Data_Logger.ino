/*
  Task 04: SD Card Data Logger
  Board: VEGA ARIES V3
  Component: MicroSD Card Module (SPI)

  This sketch is a basic SD initialization and file-write test.
  Confirm the official ARIES V3 SPI pin mapping and MbedO runtime
  support before treating the pin assignment as hardware-verified.
*/

#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("SD Card Data Logger Starting");
  Serial.println("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed.");
    Serial.println("Check SD card connections and SPI configuration.");
    return;
  }

  Serial.println("SD card initialized successfully.");

  File dataFile = SD.open("log.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.println("VEGA ARIES V3 - SD Card Data Logger");
    dataFile.println("Initial log entry written.");
    dataFile.close();

    Serial.println("File created/opened successfully.");
    Serial.println("Initial log entry written.");
  } else {
    Serial.println("Could not open log.txt for writing.");
  }
}

void loop() {
  // Initialization and one-time file-write test.
}
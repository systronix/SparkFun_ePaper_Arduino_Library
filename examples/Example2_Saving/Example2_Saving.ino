/*
  ePaper Display with SRAM and micro SD
  By: Ciara Jekel
  SparkFun Electronics
  Date: August 13th, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14892

  This example saves the current display data to the SD card as a text file and loads it to update the display.

  Hardware Connections:
  BUSY   9
  RST    8
  MISO  12
  MOSI  11
  SCK   13
  SDCS   7
  SRCS   6
  DCS    5
  D/C    4
  GND    GND
  5V     Logic Level (if using 5V logic (e.g. Arduino) connect to 5V. if using 3.3V logic (e.g. Teensy) connect to 3.3V)
  SD in SD card slot

*/
#include "SparkFun_ePaper_154.h"
#include <SPI.h>
#include <SD.h>

const byte busyPin = 9;
const byte resetPin = 8;
const byte sdCSPin = 7;
const byte srCSPin = 6;
const byte dCSPin = 5;
const byte dcPin = 4;

EPAPER_154 myEPaper;

void setup() {
  Serial.begin(9600);

  if (!myEPaper.begin(busyPin, resetPin, sdCSPin, srCSPin, dCSPin, dcPin))
    Serial.println("No SD Card Detected");

  //these functions "draw" in SRAM and are not seen until the display is updated
  myEPaper.fillScreen(RED);
  myEPaper.rectangle(12, 12, 110, 110, BLACK);
  myEPaper.rectangle(14, 14, 108, 108, WHITE);
  myEPaper.rectangle(16, 16, 106, 106, BLACK, true);
  myEPaper.rectangle(20, 20, 102, 102, WHITE, true);

  //save data from SRAM to SD card as file named "img.txt"
  myEPaper.saveToSD("img.txt");

  //load data from SD card file "img.txt" to display and update
  myEPaper.loadFromSD("img.txt");


}

void loop() {
  // put your main code here, to run repeatedly:

}


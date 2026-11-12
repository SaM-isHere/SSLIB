/*
  SHEPHERDSOFT
  SSLIB - ShepherdSoft Library

  Designed to simplify Arduino programming by
  providing reusable sensor and display functions.
*/

#ifndef SSLIB_H
#define SSLIB_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

// OLED object declaration
extern Adafruit_SSD1306 display;

class SSLIB {

  public:
    template<typename... Pins>
    void pinMODE(uint8_t mode, Pins... pins){
      (pinMode(pins, mode), ...);
    }
    // Version check
    void vv();

    // Initialization functions
    void betaINIT(int baud);
    void gammaINIT(int baud);

    // Ultrasonic Distance Sensor 200cm at max. ### Returns something
    void ultrasonicDS200();
};

#endif

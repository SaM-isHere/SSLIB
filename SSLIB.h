
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

  private:

    int sensorPin;
    bool sensorConfigured;

  public:

    // Constructor
    explicit SSLIB(int pin);

    // Raw sensor reading
    int readRawValue();

    // Calibration configurations
    float readMT_100C_CONF1();
    float readMT_100C_CONF2();

    // Analog Sensor Configuration Engine Detector
    void aSCED();

    // Initialization functions
    void betaINIT(int baud);
    void gammaINIT(int baud);

};

#endif

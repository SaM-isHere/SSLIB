/* 
SSLIB : Is made help save time in programming your arduino projects by avoiding time consumption of initialization
*/
#ifndef SSLIBH
#define SSLIBH
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

class SSLIB {
  private:
    int sensorPin;

  public:
    SSLIB(int pin);

    int readRawValue();//read the value as it is from the analog sensor pin
    float readMT_100C_CONF1(); //read mapped to 100 calibrations Configuration 1
    float readMT_100C_CONF2(); //read mapped to 100 calibrations Configuration 2
    void aSCED();//analog sensor configuration engine detector
    void betaINIT(int b);//beta initialization function. Uses less space less than 10%
    void gammaINIT(int b);//gamma initialization function. Uses Alot Of EEPROM by over 40%
};

#endif

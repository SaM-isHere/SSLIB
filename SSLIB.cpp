/*
  SHEPHERDSOFT
  SSLIB - IMPLEMENTATION
*/

#include "SSLIB.h"


// ==========================================
// OLED OBJECT DEFINITION
Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);


void SSLIB::vv(){
  Serial.println("Version 3")
}

// ==========================================
// BETA INITIALIZATION  LIGHT WEIGHT ONLY 
void SSLIB::betaINIT(int baud) {

  Serial.begin(baud);

}

// ==========================================
// GAMMA INITIALIZATION  SERIAL + OLED
void SSLIB::gammaINIT(int baud) {
  Serial.begin(baud);
  Wire.begin();
  if (!display.begin(
    SSD1306_SWITCHCAPVCC,
    OLED_ADDRESS
  )) {

    Serial.println("SSLIB: OLED initialization failed!");
    return;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("ShepherdSoft");
  display.println("SSLIB INITIALIZED");
  display.display();
  Serial.println("SSLIB: OLED initialized successfully!");

}

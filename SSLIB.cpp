
/*
  SHEPHERDSOFT
  SSLIB - IMPLEMENTATION
*/

#include "SSLIB.h"


// ==========================================
// OLED OBJECT DEFINITION
// ==========================================

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);


// ==========================================
// CONSTRUCTOR
// ==========================================

SSLIB::SSLIB(int pin) {

  sensorPin = pin;
  sensorConfigured = false;

}


// ==========================================
// RAW SENSOR READING
// ==========================================

int SSLIB::readRawValue() {

  if (!sensorConfigured) {

    pinMode(sensorPin, INPUT);
    sensorConfigured = true;

  }

  return analogRead(sensorPin);

}


// ==========================================
// CONFIGURATION 1
// 0 -> 100
// ==========================================

float SSLIB::readMT_100C_CONF1() {

  int readValue = readRawValue();

  return (readValue * 100.0) / 1023.0;

}


// ==========================================
// CONFIGURATION 2
// 100 -> 0
// ==========================================

float SSLIB::readMT_100C_CONF2() {

  int readValue = readRawValue();

  return 100.0 - (readValue * 100.0 / 1023.0);

}


// ==========================================
// ANALOG SENSOR CONFIGURATION ENGINE
// DETECTOR (aSCED)
// ==========================================

void SSLIB::aSCED() {

  const int sampleCount = 400;

  long sum = 0;

  // Collect sensor readings
  for (int i = 0; i < sampleCount; i++) {

    sum += readRawValue();

    delay(10);

  }

  // Calculate average
  float av = (float)sum / sampleCount;

  Serial.println();
  Serial.println("===== SSLIB aSCED =====");

  Serial.print("Average: ");
  Serial.println(av, 2);


  // ========================================
  // CONFIGURATION 1
  // ========================================

  Serial.println("--- CONFIGURATION 1 ---");

  if (av < 561.5) {

    Serial.println("95%+ - CONFIG1 suggested");

  }

  else if (av < 611.5) {

    Serial.println("75%+ - CONFIG1 suggested");

  }

  else if (av < 661.5) {

    Serial.println("25%+ - CONFIG1 suggested");

  }

  else if (av <= 711.5) {

    Serial.println("0%+ - CONFIG1 suggested");

  }

  else {

    Serial.println("OUT OF CONFIG1 DETECTION SCOPE");

  }


  // ========================================
  // CONFIGURATION 2
  // ========================================

  Serial.println("--- CONFIGURATION 2 ---");

  if (av > 911.5 && av <= 961.5) {

    Serial.println("95%+ - CONFIG2 suggested");

  }

  else if (av > 861.5 && av <= 911.5) {

    Serial.println("75%+ - CONFIG2 suggested");

  }

  else if (av > 811.5 && av <= 861.5) {

    Serial.println("25%+ - CONFIG2 suggested");

  }

  else if (av >= 761.5 && av <= 811.5) {

    Serial.println("0%+ - CONFIG2 suggested");

  }

  else {

    Serial.println("OUT OF CONFIG2 DETECTION SCOPE");

  }

  Serial.println("========================");

}


// ==========================================
// BETA INITIALIZATION
// SERIAL ONLY
// ==========================================

void SSLIB::betaINIT(int baud) {

  Serial.begin(baud);

}


// ==========================================
// GAMMA INITIALIZATION
// SERIAL + OLED
// ==========================================

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

  display.println("SHEPHERDSOFT");

  display.println("SSLIB INITIALIZED");

  display.display();

  Serial.println("SSLIB: OLED initialized successfully!");

}

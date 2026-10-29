  //SHEPHEREDSOFT
  #include "SSLIB.h"

  SSLIB::SSLIB(int pin){
    sensorPin = pin;
    pinMode(sensorPin,INPUT);
  }

  int SSLIB::readRawValue(){
    return analogRead(sensorPin);
  }

  float SSLIB::readMT_100C_CONF1(){
    int readValue = readRawValue();
    float MTV = map(readValue,0,1023,0,100);
    return MTV;
  }

  float SSLIB::readMT_100C_CONF2(){
    int readValue = readRawValue();
    float MTV = map(readValue,0,1023,100,0);
    return MTV;
  }

  void SSLIB::aSCED(){
    int readValue = readRawValue();
    int sArray[400] = {};
    long sum=0;
    for(int i=0; i<400; i++){
      sArray[i]=readValue;
      sum+=sArray[i];
      delay(10);
    }
    float av = (float)sum/400;
    //CONFIG1
    if(av>0 && av<561.5){
      Serial.println();
      Serial.println("95%+ - CONFIG1 suggested");
    }
    else if(av>561.5 && av<611.5){
      Serial.println();
      Serial.println("75%+ - CONFIG1 suggested");
    }
    else if(av>611.5 && av>661.5){
      Serial.println();
      Serial.println("25%+ - CONFIG1 suggested");
    }
    else if(av>661.5 && av<711.5){
      Serial.println();
      Serial.println("0%+ - CONFIG1 suggested");
    }
    else{
      Serial.println();
      Serial.println("OUT OF CONFIG1 DETECTION SCOPE");
    }
    
  //CONFIG2
    if(av>911.5 && av<961.5){
      Serial.println();
      Serial.println("95%+ - CONFIG2 suggested");
    }
    else if(av>861.5 && av<911.5){
      Serial.println();
      Serial.println("75%+ - CONFIG2 suggested");
    }
    else if(av>811.5 && av>861.5){
      Serial.println();
      Serial.println("25%+ - CONFIG2 suggested");
    }
    else if(av>761.5 && av<811.5){
      Serial.println();
      Serial.println("0%+ - CONFIG2 suggested");
    }
    else{
      Serial.println();
      Serial.println("OUT OF CONFIG2 DETECTION SCOPE");
    }
  }
  void SSLIB::betaINIT(int baud){
    Serial.begin(baud);
  }

  void SSLIB::gammaINIT(int baud){
    Serial.begin(baud);
    if (!display.begin(
      SSD1306_SWITCHCAPVCC,
      OLED_ADDRESS
    )){
      Serial.println("OLED initialization failed!");
      while(true);
    }
  }

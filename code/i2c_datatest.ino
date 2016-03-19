#include <Wire.h>

#define SENSOR_ADDR 0x68; 

void setup(){
  Wire.begin();
  
  Wire.beginTransmission(SENSOR_ADDR);
  Wire.write(0x6b);  // POWER register
  Wire.write(0x00);     // dont sleep
  Wire.endTransmission(true);
  
  Serial.begin(9600);
}

void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // begin from 0x3b
  Wire.endTransmission(false);
  
  // read 14 DATAbytes here
  // ...
  
  delay(30);
}

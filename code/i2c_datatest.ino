#include <Wire.h>

#define SENSOR_ADDR 0x68; 

unsigned char bytes[14];

void setup(){
  Wire.begin();
  
  Wire.beginTransmission(SENSOR_ADDR);
  Wire.write(0x6b);  // POWER register
  Wire.write(0x00);     // dont sleep
  Wire.endTransmission(true);
  
  Serial.begin(9600);
}

void loop(){
  Wire.beginTransmission(SENSOR_ADDR);
  Wire.write(0x3B);  // begin from 0x3b
  Wire.endTransmission(false);
  
  // request 14 bytes here
  Wire.requestFrom(SENSOR_ADDR, 14, true);
  
  // read 14 DATAbytes here
  for (int i = 0; i < 14; i++)
      bytes[i] = Wire.read();
  
  // convert into ints
  // ...
  
  delay(30);
}

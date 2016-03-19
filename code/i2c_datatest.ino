#include <Wire.h>

#define SENSOR_ADDR 0x68; 

void setup(){
  Wire.begin();
  
  Wire.beginTransmission(MPU_addr);
  Wire.write(SENSOR_ADDR);  // POWER register
  Wire.write(0x00);     // dont sleep
  Wire.endTransmission(true);
  
  Serial.begin(9600);
}

void loop(){
  // read DATA here 
  
  delay(30);
}

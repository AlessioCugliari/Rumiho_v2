#include "IMU.h"

void imuInit(){
  
  if(!IMU.begin()){
    Serial.println("Failed to initialize IMU!");
    while(1);
  }
}

void readGyro(float Gx, float Gy, float Gz){

  if(IMU.gyroscopeAvailable()){
    IMU.readGyroscope(Gx, Gy, Gz);
    
    Serial.println("Gyro data: ");
    Serial.print("Gx: ");
    Serial.print(Gx);
    Serial.print('\t');
    Serial.print(" Gy: ");
    Serial.print(Gy);
    Serial.print('\t');
    Serial.print(" Gz: ");
    Serial.print(Gz);
    Serial.println();

    delay(50);
  }
}
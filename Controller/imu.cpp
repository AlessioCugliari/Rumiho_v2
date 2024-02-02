#include "IMU.h"

void imuInit(){
  
  if(!IMU.begin()){
    Serial.println("Failed to initialize IMU!");
    while(1);
  }
}

void readGyro(float Gx, float Gy, float Gz, float *currentX, float *currentY){

  unsigned long prevTime = millis();

  if(IMU.gyroscopeAvailable()){
    IMU.readGyroscope(Gx, Gy, Gz);

    unsigned long currentTime = millis();
    float deltaT = (currentTime - prevTime);

    float angleX = Gx * deltaT;
    *currentX += angleX;

    Serial.print("prev ");
    Serial.print(prevTime);
    Serial.print('\t');
    Serial.print("curr ");
    Serial.println(currentTime);

    /*if(Gx > 0.5 || Gx < -0.5){
      float angleX = Gx * deltaT;
      *currentX += angleX;
    }*/
    
    if(Gy > 1 || Gy < -1){
      *currentY += Gy;
    }
    
    /*Serial.println("Position: ");
    Serial.print("cuttentX: ");
    Serial.print(*currentX);
    Serial.print('\t');
    Serial.print(" currentY: ");
    Serial.print(*currentY);
    Serial.println();*/


    /*Serial.println("Gyro data: ");
    Serial.print("Gx: ");
    Serial.print(Gx);
    Serial.print('\t');
    Serial.print(" Gy: ");
    Serial.print(Gy);
    Serial.print('\t');
    Serial.print(" Gz: ");
    Serial.print(Gz);
    Serial.println();*/

    delay(50);
  }
}

void readAcc(float* Ax, float* Ay, float* Az){

  if(IMU.accelerationAvailable()){

    IMU.readAcceleration(*Ax, *Ay, *Az);

    /*Serial.println("Acc data: ");
    Serial.print("Ax: ");
    Serial.print(Ax);
    Serial.print('\t');
    Serial.print(" Ay: ");
    Serial.print(Ay);
    Serial.println();*/

    delay(50);

  }
}
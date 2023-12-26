#include "motor.h"
#include "bluetooth.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motorInit();
  bluetoothInit();

  Serial.println("Setup ok!");
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*motorForward(250);
  
  delay(5000);

  motorStop();

  delay(5000);

  motorBakcward(250);

  delay(5000);

  motorTurnRight(250);

  delay(5000);

  motorStop();

  delay(5000);

  motorTurnLeft(250);

  delay(5000);*/


}

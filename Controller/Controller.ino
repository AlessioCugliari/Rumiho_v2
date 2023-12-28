#include "bluetooth.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if (!BLE.begin()) {
    Serial.println("* Starting Bluetooth® Low Energy module failed!");
    while (1);
  }

  Serial.println("Setup ok");
}

void loop() {
  // put your main code here, to run repeatedly:
  connectToPeripheral();
}

#include "motor.h"
#include "bluetooth.h"

BLEService service("19B10000-E8F2-537E-4F6C-D104768A1214"); // Bluetooth® Low Energy LED Service

// Bluetooth® Low Energy LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  motorInit();
  bluetoothInit(service, switchCharacteristic);

  delay(500);   //Some time to put the rover on the ground
  Serial.println("Setup ok!");
}

void loop() {
  // put your main code here, to run repeatedly:

  bluetoothListen(switchCharacteristic);
  
}

#include "motor.h"
#include "bluetooth.h"
#include "pixycam.h"

BLEService service("19B10000-E8F2-537E-4F6C-D104768A1214"); // Bluetooth® Low Energy LED Service

// Bluetooth® Low Energy LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);

Pixy2 pixy;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  motorInit();
  bluetoothInit(service, switchCharacteristic);
  pixy.init();
  // user color connected components program
  pixy.changeProg("color_connected_components");

  delay(500);   //Some time to put the rover on the ground
  Serial.println("Setup ok!");
}

void loop() {
  // put your main code here, to run repeatedly:

  //bluetoothListen(switchCharacteristic);
  //grabAndPrintBlock(pixy);
  
  static int16_t index = -1;
  Block *block = NULL;

  pixy.ccc.getBlocks();

  //search
  if(index == -1){
    
    Serial.println("Searching for block...");
    index = acquireBlock(pixy);
    
    
  }
  //If we found a block track it
  if(index >= 0){
    block = trackBlock(pixy, index);
  }

  if(block){
    block->print();
  }else{
    //if no object detected, stop the motor, reset the index and search again
    index = -1;
  }


}

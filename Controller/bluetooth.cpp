#include "bluetooth.h"
#include "bluetooth_secret.h"

//Central device

/*const char* deviceServiceUuid = SERVICE_UUID;
const char* deviceServiceCharacteristicUuid = SERVICE_CHARACTERISTIC_UUID;*/

void bluetoothInit(){

  if (!BLE.begin()) {
      Serial.println("* Starting Bluetooth® Low Energy module failed!");
      while (1);
  }

  BLE.setLocalName("Rumiho Controller"); 
  BLE.scan();

}
/*
void connectToPeripheral_aux(){

    BLEDevice peripheral;

    Serial.println("- Discovering peripheral device...");

    const char* deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";

    do{
        BLE.scanForUuid(deviceServiceUuid);
        peripheral = BLE.available();
        //Serial.println("Scanning...");
    }while(!peripheral);

    if(peripheral){
        Serial.println("* Peripheral device found!");
        Serial.print("* Device MAC address: ");
        Serial.println(peripheral.address());
        Serial.print("* Device name: ");
        Serial.println(peripheral.localName());
        Serial.print("* Advertised service UUID: ");
        Serial.println(peripheral.advertisedServiceUuid());
        Serial.println(" ");
       
        BLE.stopScan();

        controlPeripheral(peripheral);
    }
}*/

void controlPeripheral2(BLEDevice peripheral){}

void sendMessage(){

  float Ax,Ay,Az;

  readAcc(&Ax,&Ay,&Az);

  if(Ay > 0.30){
    Serial.println("W");
  }
  else if(Ay < -0.30){
    Serial.println("S");
  }
  else if(Ax > 0.30){
    Serial.println("D");
  }
  else if(Ax < -0.30){
    Serial.println("A");
  }
  else{
    Serial.println("Q");
  }
}
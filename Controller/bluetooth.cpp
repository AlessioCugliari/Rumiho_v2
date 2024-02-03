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

char createCommand(){

  float Ax,Ay,Az;

  readAcc(&Ax,&Ay,&Az);

  if(Ay > THRESHOLD){
    Serial.println("W");
    return 'W';
  }
  if(Ay < -THRESHOLD){
    Serial.println("S");
    return 'S';
  }
  if(Ax > THRESHOLD){
    Serial.println("D");
    return 'D';
  }
  if(Ax < -THRESHOLD){
    Serial.println("A");
    return 'A';
  }
  
  Serial.println("Q");
  return 'Q';
}
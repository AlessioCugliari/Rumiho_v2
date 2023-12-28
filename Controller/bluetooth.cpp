#include "bluetooth.h"
#include "bluetooth_secret.h"

const char* deviceServiceUuid = SERVICE_UUID;
const char* deviceServiceCharacteristicUuid = SERVICE_CHARACTERISTIC_UUID;

void bluetoothInit(){

    BLE.setLocalName("Rumiho Controller");
    BLE.advertise();
    Serial.println(deviceServiceUuid);
}

void connectToPeripheral(){

    BLEDevice peripheral;

    Serial.println("- Discovering peripheral device...");

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
}

void controlPeripheral(BLEDevice peripheral){}
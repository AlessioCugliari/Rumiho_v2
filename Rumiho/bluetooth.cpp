#include "bluetooth.h"
#include "bluetooth_secret.h"

void bluetoothInit(){

    const char* deviceServiceUuid = SERVICE_UUID;
    const char* deviceServiceCharacteristicUuid = SERVICE_CHARACTERISTIC_UUID;

    if(!BLE.begin()){
        while(1);
    }

    BLEService service(deviceServiceUuid);
    BLEStringCharacteristic characteristic(deviceServiceCharacteristicUuid);

    BLE.setLocalName("Rumiho Rover");
    BLE.setAdvertisedService(service);
    service.addCharacteristic(characteristic);
    BLE.addService(service);
    BLE.advertise();

}

void bluetoothListen(){

    BLEDevice central = BLE.central();
    delay(500);

    if(central){
        Serial.println("* Connected to central device!");
        Serial.print("* Device MAC address: ");
        Serial.println(central.address());
        Serial.println(" ");
        
        while(central.connected()){
            bluetoothReadCommand();
        }
    }
}

void bluetoothReadCommand(){
    Serial.println("DO THINGS")
}
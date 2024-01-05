#include "bluetooth.h"
#include "bluetooth_secret.h"

//PERIPHERAL

void bluetoothInit(BLEService service, BLEByteCharacteristic switchCharacteristic){

    // begin initialization
    if (!BLE.begin()) {
      Serial.println("starting Bluetooth® Low Energy module failed!");
      while (1);
    }

    // set advertised local name and service UUID:
    BLE.setLocalName("Rumiho Rover");
    BLE.setAdvertisedService(service);

    // add the characteristic to the service
    service.addCharacteristic(switchCharacteristic);

    // add service
    BLE.addService(service);
  
    // set the initial value for the characeristic:
    switchCharacteristic.writeValue(0);

    // start advertising
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
    Serial.println("DO THINGS");
}
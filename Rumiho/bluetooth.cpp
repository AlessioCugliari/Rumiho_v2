#include "bluetooth.h"
#include "bluetooth_secret.h"
#include "motor.h"

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

void bluetoothListen(BLEByteCharacteristic switchCharacteristic){

    // listen for Bluetooth® Low Energy peripherals to connect:
    BLEDevice central = BLE.central();

    // if a central is connected to peripheral:
    if (central) {
        Serial.print("Connected to central: ");
        // print the central's MAC address:
        Serial.println(central.address());

        // while the central is still connected to peripheral:
        while (central.connected()) {
          // if the remote device wrote to the characteristic,
          // use the value to control the LED:
          if (switchCharacteristic.written()) {
              /*if (switchCharacteristic.value()) {   // any value other than 0
                  Serial.println("LED on");
              } else {                              // a 0 value
                  Serial.println(F("LED off"));
              }*/
              bluetoothReadCommand(switchCharacteristic.value());
            }
        }

      // when the central disconnects, print it out:
      Serial.print(F("Disconnected from central: "));
      Serial.println(central.address());
    }
}

void bluetoothReadCommand(char cmd){
  
    switch(cmd){
      case 'W':
        Serial.println("I received W");
        motorForward(BASE_SPEED);
        break;
      case 'S':
        Serial.println("I received S");
        motorBakcward(BASE_SPEED);
        break;
      case 'D':
        Serial.println("I received D");
        motorTurnRight(BASE_SPEED);
        break;
      case 'A':
        Serial.println("I received A");
        motorTurnLeft(BASE_SPEED);
        break;
      default:
        Serial.println("Default case Q");
        motorStop();
        break;
    }
}
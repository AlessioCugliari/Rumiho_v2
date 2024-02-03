#include "bluetooth.h"
#include "imu.h"

const char* deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
const char* deviceServiceCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1214";

float Gx,Gy,Gz;

float currentX = 0;
float currentY = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  bluetoothInit();
  imuInit();

  Serial.println("Setup ok");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  BLEDevice peripheral = BLE.available();

  if (peripheral) {
    // discovered a peripheral, print out address, local name, and advertised service
    Serial.print("Found ");
    Serial.print(peripheral.address());
    Serial.print(" '");
    Serial.print(peripheral.localName());
    Serial.print("' ");
    Serial.print(peripheral.advertisedServiceUuid());
    Serial.println();

    // see if peripheral is a Rumiho Rover
    if (peripheral.localName() == "Rumiho Rover") {
      // stop scanning
      BLE.stopScan();

      explorerPeripheral(peripheral);

    }
  }
}

void explorerPeripheral(BLEDevice peripheral) {
  // connect to the peripheral
  Serial.println("Connecting ...");

  if (peripheral.connect()) {
    Serial.println("Connected");
  } else {
    Serial.println("Failed to connect!");
    return;
  }

  // discover peripheral attributes
  Serial.println("Discovering attributes ...");
  if (peripheral.discoverAttributes()) {
    Serial.println("Attributes discovered");
  } else {
    Serial.println("Attribute discovery failed!");
    peripheral.disconnect();
    return;
  }

  // read and print device name of peripheral
  Serial.println();
  Serial.print("Device name: ");
  Serial.println(peripheral.deviceName());
  Serial.print("Appearance: 0x");
  Serial.println(peripheral.appearance(), HEX);
  Serial.println();

  BLECharacteristic commandCharacteristic = peripheral.characteristic(deviceServiceCharacteristicUuid);

  if(!commandCharacteristic){
    Serial.println("* Peripheral device does not have characteristic");
    peripheral.disconnect();
    return;
  }else if(!commandCharacteristic.canWrite()){
    Serial.println("* Peripheral device does not have a writable characteristic");
    peripheral.disconnect();
    return;
  }

  while(peripheral.connected()){
    char command = createCommand();
    commandCharacteristic.writeValue((byte)command);
  }
  Serial.println();

  // we are done exploring, disconnect
  Serial.println("Disconnecting ...");
  peripheral.disconnect();
  Serial.println("Disconnected");
}
#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <ArduinoBLE.h>

void bluetoothInit(BLEService service, BLEByteCharacteristic switchCharacteristic);

void bluetoothListen(BLEByteCharacteristic switchCharacteristic);

void bluetoothReadCommand();

#endif // BLUETOOTH_H
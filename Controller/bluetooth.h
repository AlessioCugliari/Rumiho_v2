#ifndef _BLUETOOTH_H
#define _BLUETOOTH_H

#include <ArduinoBLE.h>
#include "bluetooth_secret.h"

void bluetoothInit();

void connectToPeripheral();

void controlPeripheral(BLEDevice peripheral);

#endif // _BLUETOOTH_H
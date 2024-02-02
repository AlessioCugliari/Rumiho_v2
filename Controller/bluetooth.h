#ifndef _BLUETOOTH_H
#define _BLUETOOTH_H

#include <ArduinoBLE.h>
#include "bluetooth_secret.h"
#include "imu.h"

void bluetoothInit();

void connectToPeripheral_aux();

void controlPeripheral2(BLEDevice peripheral);

void sendMessage();

#endif // _BLUETOOTH_H
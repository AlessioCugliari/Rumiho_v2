#ifndef _IMU_H
#define _IMU_H

#include <Arduino_LSM6DSOX.h>

void imuInit();

void readGyro(float Gx, float Gy, float Gz);

#endif // _IMU_H


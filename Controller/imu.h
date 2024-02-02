#ifndef _IMU_H
#define _IMU_H

#include <Arduino_LSM6DSOX.h>

#define THRESHOLD 1

void imuInit();

void readGyro(float Gx, float Gy, float Gz, float *currentX, float *currentY);

void readAcc(float Ax, float Ay, float Az);

#endif // _IMU_H


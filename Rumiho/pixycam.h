#ifndef _PIXYCAM_H
#define _PIXYCAM_H

#include <Arduino.h>
#include <Pixy2.h>
#include "motor.h"

void grabAndPrintBlock(Pixy2 pixy);

int16_t acquireBlock(Pixy2 pixy);

Block* trackBlock(Pixy2 pixy, uint16_t index);

void followBlock(Pixy2 pixy);

long calculateArea(long height, long width);

#endif // _PIXYCAM_H
#ifndef MOTOR_H
#define MOTOR_H

#include <cstdint>

#define LEFT_PIN_DIRECTION 12
#define LEFT_PIN_PWM 3
#define LEFT_PIN_BRAKE 9
#define LEFT_PIN_CURRENT_SENSING A0

#define RIGHT_PIN_DIRECTION 13
#define RIGHT_PIN_PWM 11
#define RIGHT_PIN_BRAKE 8
#define RIGHT_PIN_CURRENT_SENSING A1

#define BASE_SPEED 250

void motorInit();

void motorForward(int8_t value);

void motorBakcward(int8_t value);

void motorStop();

void motorStart(int8_t value);

void motorTurnLeft(int8_t value);

void motorTurnRight(int8_t value);

void motorSetPwmLeft(int8_t value);

void motorSetPwmRight(int8_t value);

void motorForwardPWM(int8_t rightMotorValue, int8_t leftMotorValue);

void motorBackwardOWM(int8_t rightMotorValue, int8_t leftMotorValue);

#endif // MOTOR_H
#include <Arduino.h>

#include "motor.h"

void motorInit(){

    pinMode(LEFT_PIN_DIRECTION, OUTPUT);
    pinMode(LEFT_PIN_PWM, OUTPUT);
    pinMode(LEFT_PIN_BRAKE, OUTPUT);

    pinMode(RIGHT_PIN_DIRECTION, OUTPUT);
    pinMode(RIGHT_PIN_PWM, OUTPUT);
    pinMode(RIGHT_PIN_BRAKE, OUTPUT);

}

void motorForward(int8_t value){

    motorStart(value);

    digitalWrite(LEFT_PIN_DIRECTION, LOW);
    digitalWrite(RIGHT_PIN_DIRECTION, HIGH);
}

void motorBakcward(int8_t value){

    motorStart(value);

    digitalWrite(LEFT_PIN_DIRECTION, HIGH);
    digitalWrite(RIGHT_PIN_DIRECTION, LOW);
}

void motorStart(int8_t value){
    motorSetPwmLeft(value);
    motorSetPwmRight(value);

    /*digitalWrite(LEFT_PIN_BRAKE, HIGH);
    digitalWrite(RIGHT_PIN_BRAKE, HIGH);*/
}

void motorStop(){
    motorSetPwmLeft(0);
    motorSetPwmRight(0);
    /*digitalWrite(LEFT_PIN_BRAKE, LOW);
    digitalWrite(RIGHT_PIN_BRAKE, LOW);*/
}

void motorTurnRight(int8_t value){

    motorStart(value);

    digitalWrite(LEFT_PIN_DIRECTION, HIGH);
    digitalWrite(RIGHT_PIN_DIRECTION, HIGH);
}

void motorTurnLeft(int8_t value){

    motorStart(value);

    digitalWrite(LEFT_PIN_DIRECTION, LOW);
    digitalWrite(RIGHT_PIN_DIRECTION, LOW);
}

void motorSetPwmLeft(int8_t value){
    analogWrite(LEFT_PIN_PWM, value);
}

void motorSetPwmRight(int8_t value){
    analogWrite(RIGHT_PIN_PWM, value);
}

void motorForwardPWM(int8_t rightMotorValue, int8_t leftMotorValue){
    
    motorSetPwmRight(rightMotorValue);
    motorSetPwmLeft(leftMotorValue);

    digitalWrite(LEFT_PIN_DIRECTION, LOW);
    digitalWrite(RIGHT_PIN_DIRECTION, HIGH);
}

void motorBackwardPWM(int8_t rightMotorValue, int8_t leftMotorValue){

    motorSetPwmRight(rightMotorValue);
    motorSetPwmLeft(leftMotorValue);

    digitalWrite(LEFT_PIN_DIRECTION, HIGH);
    digitalWrite(RIGHT_PIN_DIRECTION, LOW);
}
#ifndef ROBOTCAR_HEADER
#define ROBOTCAR_HEADER

#include <Arduino.h>
#include <Servo.h>

#include "UltrasonicSensor.h"

class RobotCar {

public:

    RobotCar(
        unsigned int fle, unsigned int flf, unsigned int flb,
        unsigned int fre, unsigned int frf, unsigned int frb,
        unsigned int rre, unsigned int rrf, unsigned int rrb,
        unsigned int rle, unsigned int rlf, unsigned int rlb,    
        unsigned int servoPin, unsigned int trigPin, unsigned int echoPin
    );

    // movements
    void Forward();
    void Backward();

    // A time of 550 ms is ca. 90 degree turn
    void TurnLeft(float timer = 550);
    void TurnRight(float timer = 550);

    void EnableMotors(bool enable);

    void TurnServo(unsigned int angle);

    int GetDistance();  // in cm

private:

    Servo servo;
    unsigned int servoAngle;
    unsigned int servoPin;

    UltrasonicSensor ultrasonicSensor;
    unsigned int ussTrigPin;
    unsigned int ussEchoPin;

    bool forward, backward;

    // motor pins
    unsigned int frontLeftEnablePin,  frontLeftForwardPin,  frontLeftBackwardPin;
    unsigned int frontRightEnablePin, frontRightForwardPin, frontRightBackwardPin;
    unsigned int rearRightEnablePin,  rearRightForwardPin,  rearRightBackwardPin;
    unsigned int rearLeftEnablePin,   rearLeftForwardPin,   rearLeftBackwardPin;

};

#endif
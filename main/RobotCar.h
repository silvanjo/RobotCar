#ifndef ROBOTCAR_HEADER
#define ROBOTCAR_HEADER

#include <Arduino.h>
#include <Servo.h>

#include "UltrasonicSensor.h"

enum RobotCarActions 
{
    FORWARD,
    BACKWARD,
    TURN_RIGHT,
    TURN_LEFT,
    HOLD,
    OFF
};

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
    void Hold();

    void TurnLeft();
    void TurnRight();

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

    // motor pins
    unsigned int frontLeftEnablePin,  frontLeftForwardPin,  frontLeftBackwardPin;
    unsigned int frontRightEnablePin, frontRightForwardPin, frontRightBackwardPin;
    unsigned int rearRightEnablePin,  rearRightForwardPin,  rearRightBackwardPin;
    unsigned int rearLeftEnablePin,   rearLeftForwardPin,   rearLeftBackwardPin;

    RobotCarActions currentAction;

};

#endif
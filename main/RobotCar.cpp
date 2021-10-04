#include "RobotCar.h"

RobotCar::RobotCar(
        unsigned int fle, unsigned int flf, unsigned int flb,
        unsigned int fre, unsigned int frf, unsigned int frb,
        unsigned int rre, unsigned int rrf, unsigned int rrb,
        unsigned int rle, unsigned int rlf, unsigned int rlb,    
        unsigned int servoPin, unsigned int trigPin, unsigned int echoPin
    )
    : ultrasonicSensor(trigPin, echoPin)
{

    RobotCar::servoAngle = 90;
    RobotCar::servoPin   = servoPin;
    RobotCar::forward    = false;
    RobotCar::backward   = false;
    RobotCar::hold       = true;
    
    // init motors
    RobotCar::frontLeftEnablePin    = fle;
    RobotCar::frontLeftForwardPin   = flf;
    RobotCar::frontLeftBackwardPin  = flb;

    RobotCar::frontRightEnablePin   = fre;
    RobotCar::frontRightForwardPin  = frf;
    RobotCar::frontRightBackwardPin = frb;
    
    RobotCar::rearRightEnablePin    = rre;
    RobotCar::rearRightForwardPin   = rrf;
    RobotCar::rearRightBackwardPin  = rrb;

    RobotCar::rearLeftEnablePin     = rle;
    RobotCar::rearLeftForwardPin    = rlf;
    RobotCar::rearLeftBackwardPin   = rlb;
    // -----------

    // Setup motors
    pinMode(frontLeftEnablePin,    OUTPUT);
    pinMode(frontLeftForwardPin,   OUTPUT);
    pinMode(frontLeftBackwardPin,  OUTPUT);

    pinMode(frontRightEnablePin,   OUTPUT);
    pinMode(frontRightForwardPin,  OUTPUT);
    pinMode(frontRightBackwardPin, OUTPUT);

    pinMode(rearRightEnablePin,    OUTPUT);
    pinMode(rearRightForwardPin,   OUTPUT);
    pinMode(rearRightBackwardPin,  OUTPUT);

    pinMode(rearLeftEnablePin,     OUTPUT);
    pinMode(rearLeftForwardPin,    OUTPUT);
    pinMode(rearLeftBackwardPin,   OUTPUT);
    // -------------

    // Setup servo
    servo.attach(RobotCar::servoPin);
    servo.write(RobotCar::servoAngle);
    // -------------

    // Setup Ultrasonic sensor
    RobotCar::ussTrigPin = trigPin;
    RobotCar::ussEchoPin = echoPin;
    // -------------


}

void RobotCar::Forward() 
{

    if (!RobotCar::forward)
    {

        RobotCar::forward  = true;
        RobotCar::backward = false;
        RobotCar::hold     = false;

        digitalWrite(RobotCar::frontLeftForwardPin,   true);
        digitalWrite(RobotCar::frontLeftBackwardPin,  false);

        digitalWrite(RobotCar::frontRightForwardPin,  true);
        digitalWrite(RobotCar::frontRightBackwardPin, false);

        digitalWrite(RobotCar::rearRightForwardPin,   true);
        digitalWrite(RobotCar::rearRightBackwardPin,  false);

        digitalWrite(RobotCar::rearLeftForwardPin,    true);
        digitalWrite(RobotCar::rearLeftBackwardPin,   false);

    }


}

void RobotCar::Backward() 
{

    if (!RobotCar::backward) 
    {

        RobotCar::forward  = false;
        RobotCar::backward = true;
        RobotCar::hold     = false;

        digitalWrite(RobotCar::frontLeftForwardPin,   false);
        digitalWrite(RobotCar::frontLeftBackwardPin,  true);

        digitalWrite(RobotCar::frontRightForwardPin,  false);
        digitalWrite(RobotCar::frontRightBackwardPin, true);

        digitalWrite(RobotCar::rearRightForwardPin,   false);
        digitalWrite(RobotCar::rearRightBackwardPin,  true);

        digitalWrite(RobotCar::rearLeftForwardPin,    false);
        digitalWrite(RobotCar::rearLeftBackwardPin,   true);


    }


}

void RobotCar::Hold() 
{

    if (!RobotCar::hold) 
    {

        RobotCar::forward  = false;
        RobotCar::backward = false;
        RobotCar::hold     = true;
    
        digitalWrite(RobotCar::frontLeftForwardPin,   false);
        digitalWrite(RobotCar::frontLeftBackwardPin,  false);

        digitalWrite(RobotCar::frontRightForwardPin,  false);
        digitalWrite(RobotCar::frontRightBackwardPin, false);

        digitalWrite(RobotCar::rearRightForwardPin,   false);
        digitalWrite(RobotCar::rearRightBackwardPin,  false);

        digitalWrite(RobotCar::rearLeftForwardPin,    false);
        digitalWrite(RobotCar::rearLeftBackwardPin,   false);

    }


}

void RobotCar::TurnLeft(float timer) 
{

    digitalWrite(RobotCar::frontRightForwardPin,  true);
    digitalWrite(RobotCar::frontRightBackwardPin, false);

    digitalWrite(RobotCar::rearRightForwardPin,   true);
    digitalWrite(RobotCar::rearRightBackwardPin,  false);

    digitalWrite(RobotCar::frontLeftForwardPin,   false);
    digitalWrite(RobotCar::frontLeftBackwardPin,  true);

    digitalWrite(RobotCar::rearLeftForwardPin,    false);
    digitalWrite(RobotCar::rearLeftBackwardPin,   true);
delay(10);
    if (timer == 0)
        delay(10);
    else
        delay(timer);

    digitalWrite(RobotCar::frontRightForwardPin,  false);
    digitalWrite(RobotCar::rearRightForwardPin,   false);
    digitalWrite(RobotCar::frontLeftBackwardPin,  false);
    digitalWrite(RobotCar::rearLeftBackwardPin,   false);
    
}

void RobotCar::TurnRight(float timer) 
{

    digitalWrite(RobotCar::frontRightForwardPin,  false);
    digitalWrite(RobotCar::frontRightBackwardPin, true);

    digitalWrite(RobotCar::rearRightForwardPin,   false);
    digitalWrite(RobotCar::rearRightBackwardPin,  true);

    digitalWrite(RobotCar::frontLeftForwardPin,   true);
    digitalWrite(RobotCar::frontLeftBackwardPin,  false);

    digitalWrite(RobotCar::rearLeftForwardPin,    true);
    digitalWrite(RobotCar::rearLeftBackwardPin,   false);
delay(10);
    if (timer == 0)
        delay(10);
    else
        delay(timer);

    digitalWrite(RobotCar::frontRightBackwardPin, false);
    digitalWrite(RobotCar::rearRightBackwardPin,  false);
    digitalWrite(RobotCar::frontLeftForwardPin,   false);
    digitalWrite(RobotCar::rearLeftForwardPin,    false);
    
}

void RobotCar::EnableMotors(bool enable) {

    digitalWrite(RobotCar::frontLeftEnablePin,  enable);
    digitalWrite(RobotCar::frontRightEnablePin, enable);
    digitalWrite(RobotCar::rearRightEnablePin,  enable);
    digitalWrite(RobotCar::rearLeftEnablePin,   enable);

}

void RobotCar::TurnServo(unsigned int angle) 
{

    if (angle >= 0 && angle <= 180) {
        
        RobotCar::servoAngle = angle;
        RobotCar::servo.write(RobotCar::servoAngle);

    }

}

int RobotCar::GetDistance() 
{

    return RobotCar::ultrasonicSensor.GetDistance();

}

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

    if (currentAction != RobotCarActions::FORWARD)
    {

       currentAction = RobotCarActions::FORWARD;

        digitalWrite(frontLeftForwardPin,   true);
        digitalWrite(frontLeftBackwardPin,  false);

        digitalWrite(frontRightForwardPin,  true);
        digitalWrite(frontRightBackwardPin, false);

        digitalWrite(rearRightForwardPin,   true);
        digitalWrite(rearRightBackwardPin,  false);

        digitalWrite(rearLeftForwardPin,    true);
        digitalWrite(rearLeftBackwardPin,   false);

    }


}

void RobotCar::Backward() 
{

    if (currentAction != RobotCarActions::BACKWARD) 
    {

        currentAction = RobotCarActions::BACKWARD;

        digitalWrite(frontLeftForwardPin,   false);
        digitalWrite(frontLeftBackwardPin,  true);

        digitalWrite(frontRightForwardPin,  false);
        digitalWrite(frontRightBackwardPin, true);

        digitalWrite(rearRightForwardPin,   false);
        digitalWrite(rearRightBackwardPin,  true);

        digitalWrite(rearLeftForwardPin,    false);
        digitalWrite(rearLeftBackwardPin,   true);


    }


}

void RobotCar::Hold() 
{

    if (currentAction != RobotCarActions::HOLD) 
    {
        
        currentAction = RobotCarActions::HOLD;
    
        digitalWrite(frontLeftForwardPin,   false);
        digitalWrite(frontLeftBackwardPin,  false);

        digitalWrite(frontRightForwardPin,  false);
        digitalWrite(frontRightBackwardPin, false);

        digitalWrite(rearRightForwardPin,   false);
        digitalWrite(rearRightBackwardPin,  false);

        digitalWrite(rearLeftForwardPin,    false);
        digitalWrite(rearLeftBackwardPin,   false);

    }


}

void RobotCar::TurnLeft() 
{

    if(currentAction != RobotCarActions::TURN_LEFT)
    {
        
        currentAction = RobotCarActions::TURN_LEFT;
    
        digitalWrite(frontRightForwardPin,  true);
        digitalWrite(frontRightBackwardPin, false);

        digitalWrite(rearRightForwardPin,   true);
        digitalWrite(rearRightBackwardPin,  false);

        digitalWrite(frontLeftForwardPin,   false);
        digitalWrite(frontLeftBackwardPin,  true);

        digitalWrite(rearLeftForwardPin,    false);
        digitalWrite(rearLeftBackwardPin,   true);

    }

}

void RobotCar::TurnRight() 
{
    if(currentAction != RobotCarActions::TURN_RIGHT)
    {
        
        currentAction = RobotCarActions::TURN_RIGHT;

        digitalWrite(frontRightForwardPin,  false);
        digitalWrite(frontRightBackwardPin, true);

        digitalWrite(rearRightForwardPin,   false);
        digitalWrite(rearRightBackwardPin,  true);

        digitalWrite(frontLeftForwardPin,   true);
        digitalWrite(frontLeftBackwardPin,  false);

        digitalWrite(rearLeftForwardPin,    true);
        digitalWrite(rearLeftBackwardPin,   false);
    
    }
    
}

void RobotCar::EnableMotors(bool enable) {

    digitalWrite(frontLeftEnablePin,  enable);
    digitalWrite(frontRightEnablePin, enable);
    digitalWrite(rearRightEnablePin,  enable);
    digitalWrite(rearLeftEnablePin,   enable);

}

void RobotCar::TurnServo(unsigned int angle) 
{

    if (angle >= 0 && angle <= 180) {
        
        servoAngle = angle;
        servo.write(servoAngle);

    }

}

int RobotCar::GetDistance() 
{

    return ultrasonicSensor.GetDistance();

}

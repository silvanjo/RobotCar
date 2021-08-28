#include "RobotCarController.h"
#include "defines.h"

RobotCarController::RobotCarController
(
    unsigned int fle, unsigned int flf, unsigned int flb,
    unsigned int fre, unsigned int frf, unsigned int frb,
    unsigned int rre, unsigned int rrf, unsigned int rrb,
    unsigned int rle, unsigned int rlf, unsigned int rlb,    
    unsigned int servoPin, unsigned int trigPin, unsigned int echoPin
) 
    : robotCar 
    (
        fle, flf, flb,
        fre, frf, frb,
        rre, rrf, rrb,
        rle, rlf, rlb,
        servoPin, trigPin, echoPin
    )
{

    RobotCarController::active = false;
    RobotCarController::forwardFailCounter = 0;

}

void RobotCarController::StartObstacleAvoidingProtocol()
{

    RobotCarController::active = true;
    RobotCarController::robotCar.EnableMotors(true);

    while (RobotCarController::active) 
    {

        int distance = RobotCarController::robotCar.GetDistance();

        if (distance <= 25) 
        {

            RobotCarController::forwardFailCounter++;

            if (RobotCarController::forwardFailCounter >= 3) 
            {

                RobotCarController::robotCar.Backward();
                delay(2000);

            }

            RobotCarController::robotCar.Hold();

            RobotCarController::robotCar.TurnServo(SERVO_LEFT);

            delay(900);

            int distanceLeft = RobotCarController::robotCar.GetDistance();

            RobotCarController::robotCar.TurnServo(SERVO_RIGHT);

            delay(1400);

            int distanceRight = RobotCarController::robotCar.GetDistance();

            RobotCarController::robotCar.TurnServo(SERVO_MIDDLE);

            if (distanceLeft <= 25 && distanceRight <= 25)
            {

                RobotCarController::robotCar.Backward();
                delay(2000);
                RobotCarController::robotCar.TurnRight();

            }
            else if (distanceLeft > distanceRight)
            {

                RobotCarController::robotCar.TurnLeft();

            }
            else 
            {

                RobotCarController::robotCar.TurnRight();

            }


        }
        else 
        {

            RobotCarController::robotCar.Forward();
            RobotCarController::forwardFailCounter = 0;

        }

    }

}
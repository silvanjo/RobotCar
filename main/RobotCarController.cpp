#include "RobotCarController.h"

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

}

void RobotCarController::StartObstacleAvoidingProtocol()
{

    RobotCarController::active = true;
    RobotCarController::robotCar.EnableMotors(true);

    while (RobotCarController::active) 
    {

        

    }

}
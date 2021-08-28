#ifndef ROBOTCAR_CONTROLLER_HEADER
#define ROBOTCAR_CONTROLLER_HEADER

#include "RobotCar.h"
#include "Arduino.h"

class RobotCarController 
{

public:

    RobotCarController
    (
        unsigned int fle, unsigned int flf, unsigned int flb,
        unsigned int fre, unsigned int frf, unsigned int frb,
        unsigned int rre, unsigned int rrf, unsigned int rrb,
        unsigned int rle, unsigned int rlf, unsigned int rlb,    
        unsigned int servoPin, unsigned int trigPin, unsigned int echoPin
    );

    void StartObstacleAvoidingProtocol();

private:

    RobotCar robotCar;
    bool active;

    int forwardFailCounter; // if car fails to drive forward three times in row drive backwards

};

#endif
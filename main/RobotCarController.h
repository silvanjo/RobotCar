#ifndef ROBOTCAR_CONTROLLER_HEADER
#define ROBOTCAR_CONTROLLER_HEADER

#include "RobotCar.h"
#include "Arduino.h"
#include "defines.h"

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

class RobotCarController 
{

public:

    RobotCarController
    (
        unsigned int fle, unsigned int flf, unsigned int flb,
        unsigned int fre, unsigned int frf, unsigned int frb,
        unsigned int rre, unsigned int rrf, unsigned int rrb,
        unsigned int rle, unsigned int rlf, unsigned int rlb,    
        unsigned int servoPin, unsigned int trigPin, unsigned int echoPin,
         int CE_pin = -1, int CSN_pin = -1, char address[NRF24L01_ADDRESS_LENGTH_STR] = "00000"
    );

    void StartObstacleAvoidingProtocol();

private:

    RobotCar robotCar;
    bool active;

    int forwardFailCounter; // if car fails to drive forward three times in row drive backwards

    RF24 receiver;
    int CE_pin;
    int CSN_pin;
    char address[NRF24L01_ADDRESS_LENGTH_STR];

};

#endif
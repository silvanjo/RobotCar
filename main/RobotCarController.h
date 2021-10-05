#ifndef ROBOTCAR_CONTROLLER_HEADER
#define ROBOTCAR_CONTROLLER_HEADER

#define SERVO_RIGHT 0
#define SERVO_MIDDLE 90
#define SERVO_LEFT 180

#define NRF24L01_ADDRESS_LENGTH 5
#define NRF24L01_ADDRESS_LENGTH_STR NRF24L01_ADDRESS_LENGTH + 1 

#include "RobotCar.h"
#include "Arduino.h"
#include "defines.h"

#include "C:/Users/Silvan Josten/Desktop/Arduino/RobotCar/RemoteControl/RCDataStruct.h" // TODO: relative path

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

enum RobotCarModes 
{
    REMOTE_CONTROL,
    OBASTACLE_AVOIDING,
};

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
        int CE_pin = -1, int CSN_pin = -1, byte address[NRF24L01_ADDRESS_LENGTH_STR] = "00000"
    );

    void Start();
    void StartObstacleAvoidingProtocol();
    void StartRemoteControlProtocol();

    bool ReceiveData();

private:

    RobotCar robotCar;
    bool active;

    int forwardFailCounter;         // if car fails to drive forward three times in row drive backwards
    int turn90DegreeTimer = 500;    // in ms

    RF24 receiver;
    int CE_pin;
    int CSN_pin;
    byte address[NRF24L01_ADDRESS_LENGTH_STR];

    RCData rc_data;

    RobotCarModes currentMode;

    bool button5Pressed;

};

#endif

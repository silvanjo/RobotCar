#include "RobotCarController.h"


RobotCarController::RobotCarController
(
    unsigned int fle, unsigned int flf, unsigned int flb,
    unsigned int fre, unsigned int frf, unsigned int frb,
    unsigned int rre, unsigned int rrf, unsigned int rrb,
    unsigned int rle, unsigned int rlf, unsigned int rlb,    
    unsigned int servoPin, unsigned int trigPin, unsigned int echoPin,
    int CE_pin, int CSN_pin, byte address[NRF24L01_ADDRESS_LENGTH_STR]
) 
    : robotCar 
    (
        fle, flf, flb,
        fre, frf, frb,
        rre, rrf, rrb,
        rle, rlf, rlb,
        servoPin, trigPin, echoPin
    ),
      receiver(CE_pin, CSN_pin)
{

    RobotCarController::active = true;
    RobotCarController::forwardFailCounter = 0;
    
    // Setup the receiver (NRF24L01)
    RobotCarController::CE_pin  = CE_pin;
    RobotCarController::CSN_pin = CSN_pin;
    strncpy(RobotCarController::address, address, NRF24L01_ADDRESS_LENGTH_STR);

    if (CE_pin != -1 && CSN_pin != -1) 
    {

        receiver.begin();
        receiver.openReadingPipe(0, address);
        receiver.setPALevel(RF24_PA_MIN);
        receiver.startListening();

    }
    // -------------

    button5Pressed = false;

    currentMode = RobotCarModes::REMOTE_CONTROL;

}

void RobotCarController::Start() 
{
    while (active)
    {
        switch(currentMode)
        {
            case RobotCarModes::OBASTACLE_AVOIDING:
                StartObstacleAvoidingProtocol();
            break;
            case RobotCarModes::REMOTE_CONTROL:
                StartRemoteControlProtocol();
            break;
        };
    }
}

bool RobotCarController::ReceiveData()
{
    if (receiver.available())
    {
        receiver.read(&rc_data, sizeof(RCData));
        return true;
    }

    return false;
}

void RobotCarController::StartObstacleAvoidingProtocol()
{

    robotCar.EnableMotors(true);

    while (currentMode == RobotCarModes::OBASTACLE_AVOIDING) 
    {

        ReceiveData();

        if (rc_data.button5 && !button5Pressed) 
        {
            button5Pressed = true;

            currentMode = RobotCarModes::REMOTE_CONTROL;
            break;
        }
        else if (button5Pressed && !rc_data.button5)
        {
            button5Pressed = false;
        }

        int distance = robotCar.GetDistance();

        if (distance <= 25) 
        {

            forwardFailCounter++;

            if (forwardFailCounter >= 3) 
            {

                robotCar.Backward();
                delay(2000);

            }

            robotCar.Hold();

            robotCar.TurnServo(SERVO_LEFT);

            delay(900);

            int distanceLeft = robotCar.GetDistance();

            robotCar.TurnServo(SERVO_RIGHT);

            delay(1400);

            int distanceRight = robotCar.GetDistance();

            robotCar.TurnServo(SERVO_MIDDLE);

            if (distanceLeft <= 25 && distanceRight <= 25)
            {

                robotCar.Backward();
                delay(2000);
                robotCar.TurnRight();
                delay(turn90DegreeTimer);
                robotCar.Hold();

            }
            else if (distanceLeft > distanceRight)
            {
                robotCar.TurnLeft();
                delay(turn90DegreeTimer);
                robotCar.Hold();
            }
            else 
            {
                robotCar.TurnRight();
                delay(turn90DegreeTimer);
                robotCar.Hold();
            }


        }
        else 
        {

            robotCar.Forward();
            forwardFailCounter = 0;

        }

    }

    robotCar.EnableMotors(false);

}

void RobotCarController::StartRemoteControlProtocol() 
{

    robotCar.EnableMotors(true);

    while(currentMode == RobotCarModes::REMOTE_CONTROL)
    {

        ReceiveData();

        if (rc_data.button5 && !button5Pressed) 
        {
            button5Pressed = true;

            currentMode = RobotCarModes::OBASTACLE_AVOIDING;
            break;
        }
        else if (button5Pressed && !rc_data.button5)
        {
            button5Pressed = false;
        }

        if (rc_data.button1 || rc_data.joy_y_val < 300)
        {
            robotCar.Forward();
        }
        else if (rc_data.button3 || rc_data.joy_y_val > 800)
        {
            robotCar.Backward();
        }
        else if (rc_data.button2 || rc_data.joy_x_val < 300)
        {
            robotCar.TurnLeft();
        }
        else if (rc_data.button4 || rc_data.joy_x_val > 800)
        {
            robotCar.TurnRight();
        }
        else 
        {
            robotCar.Hold();
        }

    }

    robotCar.EnableMotors(false);

}

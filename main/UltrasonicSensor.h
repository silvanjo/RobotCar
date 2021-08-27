#ifndef ULTRASONIC_SENSOR_HEADER
#define ULTRASONIC_SENSOR_HEADER

#include "Arduino.h"

class UltrasonicSensor {

public:

    UltrasonicSensor(unsigned int trig_pin, unsigned int echo_pin);

    int GetDistance();  // in cm

private:

    unsigned int trigPin;
    unsigned int echoPin;
    
    long duration;        // variable for the duration of sound wave travel
    int distance;         // variable for the distance measurement (cm) 

};


#endif
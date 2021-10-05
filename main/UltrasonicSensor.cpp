#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(unsigned int trigPin, unsigned int echoPin) {

    UltrasonicSensor::trigPin = trigPin;
    UltrasonicSensor::echoPin = echoPin;
    
    duration = 0;
    distance = 0;

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

}

int UltrasonicSensor::GetDistance() {

    // Clears the trigPin condition
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);

    // Calculate the distance
    distance = (int) (duration * 0.034f / 2 );

    return distance;

}
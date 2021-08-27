#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(unsigned int trigPin, unsigned int echoPin) {

    UltrasonicSensor::trigPin = trigPin;
    UltrasonicSensor::echoPin = echoPin;
    
    UltrasonicSensor::duration = 0;
    UltrasonicSensor::distance = 0;

    pinMode(UltrasonicSensor::trigPin, OUTPUT);
    pinMode(UltrasonicSensor::echoPin, INPUT);

}

int UltrasonicSensor::GetDistance() {

    // Clears the trigPin condition
    digitalWrite(UltrasonicSensor::trigPin, LOW);
    delayMicroseconds(2);

    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(UltrasonicSensor::trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(UltrasonicSensor::trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    UltrasonicSensor::duration = pulseIn(echoPin, HIGH);

    // Calculate the distance
    UltrasonicSensor::distance = (int) (UltrasonicSensor::duration * 0.034f / 2 );

    return UltrasonicSensor::distance;

}
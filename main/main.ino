#include "defines.h"
#include "RobotCarController.h"

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RobotCarController* controller = nullptr;

RF24 radio(CE, CSN);
const byte address[6] = "00001";

RCData data;

void setup() {
  
  Serial.begin(9600);

  controller = new RobotCarController(
      LEFT_EN,   LEFT_FORWARD,  LEFT_BACKWARD,
      RIGHT_EN,  RIGHT_FORWARD, RIGHT_BACKWARD,
      RIGHT_EN,  RIGHT_FORWARD, RIGHT_BACKWARD,
      LEFT_EN,   LEFT_FORWARD,  LEFT_BACKWARD,
      SERVO_PIN, USS_TRIG_PIN,  USS_ECHO_PIN,
      CE,        CSN,           "00001"
    );
  
}

void loop() {

  controller->Start();
  
}

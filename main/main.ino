#include "defines.h"
#include "RobotCarController.h"

RobotCarController* controller = nullptr;

void setup() {
  
  Serial.begin(9600);

  controller = new RobotCarController(
      LEFT_EN, LEFT_FORWARD, LEFT_BACKWARD,
      RIGHT_EN, RIGHT_FORWARD, RIGHT_BACKWARD,
      RIGHT_EN, RIGHT_FORWARD, RIGHT_BACKWARD,
      LEFT_EN, LEFT_FORWARD, LEFT_BACKWARD,
      SERVO_PIN, USS_TRIG_PIN, USS_ECHO_PIN
    );
  
}

void loop() {

  controller->StartObstacleAvoidingProtocol();
  
}

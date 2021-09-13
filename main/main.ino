#include "defines.h"
#include "RobotCarController.h"

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE  A0
#define CSN A1

RobotCarController* controller = nullptr;

RF24 radio(CE, CSN);
const byte address[6] = "00001";

void setup() {
  
  Serial.begin(9600);

  controller = new RobotCarController(
      LEFT_EN, LEFT_FORWARD, LEFT_BACKWARD,
      RIGHT_EN, RIGHT_FORWARD, RIGHT_BACKWARD,
      RIGHT_EN, RIGHT_FORWARD, RIGHT_BACKWARD,
      LEFT_EN, LEFT_FORWARD, LEFT_BACKWARD,
      SERVO_PIN, USS_TRIG_PIN, USS_ECHO_PIN
    );

  // Setop radio module
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
}

void loop() {

  // controller->StartObstacleAvoidingProtocol();

  if (radio.available()) 
  {
    
    int text[5];
    radio.read(&text, sizeof(text));

    for (int i = 0; i < 5; i++) 
    {

      Serial.print(text[i]);
      Serial.print(", ");
      
    }
    Serial.println();
  
  }
  
}

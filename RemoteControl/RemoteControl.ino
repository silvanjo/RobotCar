
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include "RCDataStruct.h"

#define CE  2
#define CSN 3

#define BUTTON_1 5
#define BUTTON_2 6
#define BUTTON_3 7
#define BUTTON_4 8

RF24 radio(CE, CSN);
const byte address[6] = "00001";

RCData data;

void setup() {

  for (int i = 0; i < 4; i++) 
    pinMode(BUTTON_1 + i, INPUT);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  Serial.begin(6900);

}

void loop() {
  
  if (digitalRead(BUTTON_1))
    data.button1 = BUTTON_PRESSED
  if (digitalRead(BUTTON_2))
    data.button2 = BUTTON_PRESSED
  if (digitalRead(BUTTON_3))
    data.button3 = BUTTON_PRESSED
  if (digitalRead(BUTTON_4))
    data.button4 = BUTTON_PRESSED
    
  radio.write(&data, sizeof(RCData)); 

  delay(1000);

}
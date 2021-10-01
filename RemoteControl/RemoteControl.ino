
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
#define BUTTON_5 9
#define BUTTON_6 10

#define JOY_X_PIN A0
#define JOY_Y_PIN A1

#define ROTARY_SWITCH_TOGGLE_PIN A2   // ignored
#define ROTARY_SWITCH_CLK A3
#define ROTARY_SWITCH_DT A4

RF24 radio(CE, CSN);
const byte address[6] = "00001";

RCData data;

int lastStateCLK;
int currentStateCLK;

void setup() {

  // init buttons
  for (int i = 0; i < 6; i++) 
    pinMode(BUTTON_1 + i, INPUT);
    // -------------

  // init buttons
  pinMode(ROTARY_SWITCH_CLK, INPUT);
  pinMode(ROTARY_SWITCH_DT, INPUT);
  lastStateCLK = digitalRead(ROTARY_SWITCH_CLK);
  // -------------


  // init RC-Module RF24
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  // -------------

}

void loop() {

  // Buttons
  data.button1 = digitalRead(BUTTON_1);
  data.button2 = digitalRead(BUTTON_2);
  data.button3 = digitalRead(BUTTON_3);
  data.button4 = digitalRead(BUTTON_4);
  data.button5 = digitalRead(BUTTON_5);
  data.button6 = digitalRead(BUTTON_6);
  // -------

  // Joystick
  data.joy_x_val = analogRead(JOY_X_PIN);
  data.joy_y_val = analogRead(JOY_Y_PIN);
  // --------

  // Rotary Switch

  currentStateCLK = digitalRead(ROTARY_SWITCH_CLK);

  // If the last and current state of CLK are different the rotary switch was rotated
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1)
  {
    // If the DT state is different than the CLK state the rotary switch was rotated CCW
    if (digitalRead(ROTARY_SWITCH_DT) != currentStateCLK)
    {
      data.rotary_switch_val--;
    }
    // In this case the switch was rotated CW
    else 
    {
      data.rotary_switch_val++;
    }
  }

  lastStateCLK = currentStateCLK;

  // -------------
  
  radio.write(&data, sizeof(RCData));   

  delay(5);

}

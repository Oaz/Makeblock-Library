/*************************************************************************
* Author             : Oaz - https://github.com/Oaz/Makeblock-Library
* Description        : Bot dances...
* License            : CC-BY-SA 3.0
**************************************************************************/
#include <MBot.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MBotLeftWheel leftWheel;
MBotRightWheel rightWheel;

void setup() {
}

void loop() {
  for(int i=0; i<4; i++)
  {
    backwardLeft();
    backwardRight();
    front();
    backwardRight();
    backwardLeft();
    front();
  }
  step(100,100,2500);
}

void backwardLeft() {
  step(-150, 0,400);
}

void backwardRight() {
  step(0,-150,400);
}

void front() {
  step(100,100,250);
}

void step(int leftSpeed, int rightSpeed, int duration) {
  leftWheel.move(leftSpeed);
  rightWheel.move(rightSpeed);
  delay(duration);
  leftWheel.stop();
  rightWheel.stop();
}




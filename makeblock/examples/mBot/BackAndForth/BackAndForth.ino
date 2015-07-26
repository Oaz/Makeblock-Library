/*************************************************************************
* Author             : Oaz - https://github.com/Oaz/Makeblock-Library
* Description        : Bot goes forward with blinking green leds
*                      When ultrasonic sensor detects an obstacle, bot goes backward with blinking red light and sound
* License            : CC-BY-SA 3.0
**************************************************************************/
#include <MBot.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MeUltrasonicSensor UltrasonicSensor(PORT_3);
MeBuzzer buzzer;
MBotRGBLed led;
MBotLeftWheel leftWheel;
MBotRightWheel rightWheel;

unsigned long time;
double distance;
uint8_t red,green,blue;
int speed;
unsigned long endOfFear;
uint16_t soundOfFear[] = {55,110,220,440,880,1760,3520,1760,880,440,220,110,55};
int soundIndex;

void setup()
{
  red = 0;
  green = 255;
  blue = 0;
  speed = 0;
  endOfFear = 0;
  soundIndex = -1;
}

void loop()
{
  time = millis();
  distance = UltrasonicSensor.distanceCm();
  if(distance < 8.0)
  {
    endOfFear = time + 1000;
    if(soundIndex < 0)
      soundIndex = 0;
  }

  if(time > endOfFear)
  {
    red = 0;
    green = 255 * ((time/600) % 2);
    speed = 100;
  }
  else
  {
    green = 0;
    red = 255 * ((time/200) % 2);
    speed = -150;
  }
  led.setColorAt(0,red,green,blue);
  led.setColorAt(1,red,green,blue);
  led.show();
  leftWheel.move(speed);
  rightWheel.move(speed);
  if(soundIndex >= 0)
  {
    buzzer.tone(soundOfFear[soundIndex], 50);
    soundIndex++;
    if(soundIndex >= sizeof(soundOfFear)/sizeof(uint16_t))
      soundIndex = -1;
  }
  else
  {
    buzzer.noTone();
  }
  delay(50);
}






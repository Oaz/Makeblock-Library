/*************************************************************************
* Author             : Oaz - https://github.com/Oaz/Makeblock-Library
* Description        : Light sensor triggers leds switch on/off
* License            : CC-BY-SA 3.0
**************************************************************************/

#include <MBot.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MBotLightSensor lightSensor;
MBotRGBLed led;

uint16_t input;
uint8_t output;
uint32_t time;
uint32_t endOfLight;

void setup()
{
  output = 0;
}

void loop()
{
  time = millis();
  input = lightSensor.read();
  if( input < 700 )
  {
    output = 255 - (input / 4);
    endOfLight = time + 5000;
  }
  if( time > endOfLight )
  {
    output = 0;
  }
  led.setColorAt(0,output,output,output);
  led.setColorAt(1,output,output,output);
  led.show();
  delay(200);
}






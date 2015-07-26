/*************************************************************************
* Author             : Oaz - https://github.com/Oaz/Makeblock-Library
* Description        : Buzzer plays Beethoven's "Ode to Joy"
* License            : CC-BY-SA 3.0
**************************************************************************/
#include <MBot.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MeBuzzer buzzer;

typedef struct
{
  uint16_t frequency;
  uint8_t duration;
} Note;

void playNote(Note *note, uint16_t baseDelay);
void playScore(Note *score, uint16_t tempo);

Note ode_to_joy[] = {
  { NOTE_D5,  16 },
  { NOTE_D5,  16 },
  { NOTE_DS5, 16 },
  { NOTE_F5,  16 },
  { NOTE_F5,  16 },
  { NOTE_DS5, 16 },
  { NOTE_D5,  16 },
  { NOTE_C5,  16 },
  { NOTE_AS4, 16 },
  { NOTE_AS4, 16 },
  { NOTE_C5,  16 },
  { NOTE_D5,  16 },
  { NOTE_D5,  24 },
  { NOTE_C5,   8 },
  { NOTE_C5,  32 },
  {       0,   0 }
};

void setup()
{
}

void loop()
{
  playScore(ode_to_joy, 130);
  delay(600);
}

void playScore(Note *score, uint16_t tempo)
{
  #define MILLISECONDS_PER_MINUTE 60000
  #define CROTCHET_LENGTH 16
  uint16_t baseDelay = MILLISECONDS_PER_MINUTE / (CROTCHET_LENGTH * tempo);
  while (score->frequency > 0)
  {
    playNote(score,baseDelay);
    score++;
  }
}

void playNote(Note *note, uint16_t baseDelay)
{
  buzzer.tone(note->frequency);
  delay(note->duration*baseDelay);
  buzzer.noTone();
}


/*
  Melody
 
 Plays a melody 
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */
 #include "pitches.h"

// notes in the melody:
//int melody[] = {
//  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4,4,4,4,4 };

int incomingByte;
int ledPinRed = 7;
int ledPinGreen = 6;


int melody[]
{
  NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7, NOTE_B7, NOTE_C8
};


void setup() {
  // iterate over the notes of the melody:
//  for (int thisNote = 0; thisNote < 8; thisNote++) {
//
//    // to calculate the note duration, take one second 
//    // divided by the note type.
//    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//    int noteDuration = 1000/noteDurations[thisNote];
//    tone(8, melody[thisNote],noteDuration);
//
//    // to distinguish the notes, set a minimum time between them.
//    // the note's duration + 30% seems to work well:
//    int pauseBetweenNotes = noteDuration * 1.30;
//    delay(pauseBetweenNotes);
//    // stop the tone playing:
//    noTone(8);
//  }
  Serial.begin(9600);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
}

void input(int in){
  int noteDuration = 1000/4;
  
  if(in % 2==0){
    digitalWrite(ledPinGreen, LOW);
    digitalWrite(ledPinRed, HIGH);
  } else{
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinGreen, HIGH);
  }
  tone(8, melody[in-1],noteDuration);
}

void loop() {
  // no need to repeat the melody.
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    //incomingByte = Serial.read();
    incomingByte = Serial.parseInt();
    //modulus for even and odd
    // if it's a capital H (ASCII 72), turn on the LED:
    // count(incomingByte);
    input(incomingByte);
  }
}

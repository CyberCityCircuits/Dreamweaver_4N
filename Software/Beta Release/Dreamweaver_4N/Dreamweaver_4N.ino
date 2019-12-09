#include "pitches.h"
#include <Keypad.h>

int speaker = 5;

//Position 1
int led_1    =  9;
int switch_1 = 13;
int pot_1    = 19;

//Position 2
int led_2    =  6;
int switch_2 = 12;
int pot_2    = 18;

//Position 3
int led_3    =  7;
int switch_3 = 11;
int pot_3    = 17;

//Position 4
int led_4    =  8;
int switch_4 = 10;
int pot_4    = 16;

//Duration
int pot_5    = 14;

//Spacing
int pot_6    = 15;

int value_knob_1;
int value_knob_2;
int value_knob_3;
int value_knob_4;
int value_knob_5;
int value_knob_6;

int note_1;
int note_2;
int note_3;
int note_4;
int duration;
int spacing;

/*
//Chromatic
int notes[] = {
//    C1, CS1, D1, DS1, E1, F1, FS1, G1, GS1, A1, AS1, B1,
    C2, CS2, D2, DS2, E2, F2, FS2, G2, GS2, A2, AS2, B2,
    C3, CS3, D3, DS3, E3, F3, FS3, G3, GS3, A3, AS3, B3,
    C4, CS4, D4, DS4, E4, F4, FS4, G4, GS4, A4, AS4, B4,
    C5, CS5, D5, DS5, E5, F5, FS5, G5, GS5, A5, AS5, B5,  
    C6, CS6, D6, DS6, E6, F6, FS6, G6, GS6, A6, AS6, B6  
};
*/

/*
//Major
int notes[] = {
//    C1, D1, E1, F1, G1, A1, B1,
    C2, D2, E2, F2, G2, A2, B2,
    C3, D3, E3, F3, G3, A3, B3,
    C4, D4, E4, F4, G4, A4, B4,
    C5, D5, E5, F5, G5, A5, B5,  
    C6, D6, E6, F6, G6, A6, B6,  
    C7
};
*/

//Minor
int notes[] = {
//    C1, D1, E1, F1, G1, A1, B1,
    C2, D2, DS2, F2, G2, GS2, AS2,
    C3, D3, DS3, F3, G3, GS3, AS3,
    C4, D4, DS4, F4, G4, GS4, AS4,
    C5, D5, DS5, F5, G5, GS5, AS5,
    C6, D6, DS6, F6, G6, GS6, AS6,
    C7
};



int notes_size = (sizeof(notes) / sizeof(notes[0]));;
int max_knob_value = 935;
float conv_factor = ((max_knob_value * 1.00) / (notes_size * 1.00));




void setup(){
  Serial.begin(9600);
  
  //Serial.print("Size of Notes: "); Serial.println(notes_size);
  //Serial.print("Conversion Factor: "); Serial.println(conv_factor);

    
  pinMode(led_1,   OUTPUT);
  pinMode(led_2,   OUTPUT);
  pinMode(led_3,   OUTPUT);
  pinMode(led_4,   OUTPUT);

  pinMode(switch_1, INPUT);
  pinMode(switch_2, INPUT);
  pinMode(switch_3, INPUT);
  pinMode(switch_4, INPUT);

  digitalWrite(led_1, HIGH); delay(50); digitalWrite(led_1, LOW);
  digitalWrite(led_2, HIGH); delay(50); digitalWrite(led_2, LOW);
  digitalWrite(led_3, HIGH); delay(50); digitalWrite(led_3, LOW);
  digitalWrite(led_4, HIGH); delay(50); digitalWrite(led_4, LOW);
  digitalWrite(led_3, HIGH); delay(50); digitalWrite(led_3, LOW);
  digitalWrite(led_2, HIGH); delay(50); digitalWrite(led_2, LOW);
  digitalWrite(led_1, HIGH); delay(50); digitalWrite(led_1, LOW);
  
  check_knobs();  

  
}

void loop(){
  play_knobs();
}

void check_knobs(){
  value_knob_1 = analogRead(pot_1);
  value_knob_2 = analogRead(pot_2);
  value_knob_3 = analogRead(pot_3);
  value_knob_4 = analogRead(pot_4);
  value_knob_5 = analogRead(pot_5);
  value_knob_6 = analogRead(pot_6);

  note_1   = value_knob_1 / conv_factor;
  note_2   = value_knob_2 / conv_factor;
  note_3   = value_knob_3 / conv_factor;
  note_4   = value_knob_4 / conv_factor;
  duration = value_knob_5;
  spacing  = value_knob_6;
  
  Serial.print(" Note 1: "); Serial.print(note_1); Serial.print(" - "); Serial.print(digitalRead(switch_1));
  Serial.print(" Note 2: "); Serial.print(note_2); Serial.print(" - "); Serial.print(digitalRead(switch_2));
  Serial.print(" Note 3: "); Serial.print(note_3); Serial.print(" - "); Serial.print(digitalRead(switch_3));
  Serial.print(" Note 4: "); Serial.print(note_4); Serial.print(" - "); Serial.print(digitalRead(switch_4));
  Serial.print(" Duration: "); Serial.print(duration);
  Serial.print(" Spacing: ");  Serial.print(spacing);
  Serial.println();

  /*
  Serial.print(" Pot 1: "); Serial.print(value_knob_1); Serial.print(" - "); Serial.print(note_1);
  Serial.print(" Pot 2: "); Serial.print(value_knob_2); Serial.print(" - "); Serial.print(note_2);
  Serial.print(" Pot 3: "); Serial.print(value_knob_3); Serial.print(" - "); Serial.print(note_3);
  Serial.print(" Pot 4: "); Serial.print(value_knob_4); Serial.print(" - "); Serial.print(note_4);
  Serial.print(" Pot 5: "); Serial.print(value_knob_5);
  Serial.print(" Pot 6: "); Serial.print(value_knob_6);
  Serial.println();
  */

}

void play_knobs(){

  if (digitalRead(switch_1) == 1){playNote(note_1, led_1);check_knobs();}
  if (digitalRead(switch_2) == 1){playNote(note_2, led_2);check_knobs();}
  if (digitalRead(switch_3) == 1){playNote(note_3, led_3);check_knobs();}
  if (digitalRead(switch_4) == 1){playNote(note_4, led_4);check_knobs();}
}

void light_led(){
  Serial.print(" Switch 1: "); Serial.print(digitalRead(switch_1));
  Serial.print(" Switch 2: "); Serial.print(digitalRead(switch_2));
  Serial.print(" Switch 3: "); Serial.print(digitalRead(switch_3));
  Serial.print(" Switch 4: "); Serial.print(digitalRead(switch_4));
  Serial.println();
}


void playNote(int note, int led) {
  digitalWrite(led, HIGH);
 if (note >= 35){
  tone(speaker, notes[36], duration);
 }
 else{
  tone(speaker, notes[note], duration);
 }
  delay(duration);
  digitalWrite(led, LOW);  
  delay(spacing);
}

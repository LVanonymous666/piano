#include <NanitLib.h>
#include "pitches.h"

byte button1 = P4_2;
byte button2 = P3_2;
byte button3 = P3_3;
byte button4 = P3_4;

byte buzzer = P4_4;
byte potentiometer = P4_1;

void setup() {
  Nanit_Base_Start();
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  pinMode(potentiometer, INPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int potentiometerValue = analogRead(potentiometer) / 10;
  if(digitalRead(button1) == 0) {
    tone(buzzer, A3 + potentiometerValue);

  } else if(digitalRead(button2) == 0) {
    tone(buzzer, C4 + potentiometerValue);

  } else if(digitalRead(button3) == 0) {
    tone(buzzer, D4 + potentiometerValue);

  } else if(digitalRead(button4) == 0) {
    tone(buzzer, DS4 + potentiometerValue);
  } else {
    noTone(buzzer);
  }

  delay(50);

}

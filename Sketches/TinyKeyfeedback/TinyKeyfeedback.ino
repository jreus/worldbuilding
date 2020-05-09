#include "DigiKeyboard.h"

#define A_PIN 3

void setup() {
  // don't need to set anything up to use DigiKeyboard
  pinMode(A_PIN, INPUT);
}

int a_val = 0, mapped = 0, a_last = 0;

void loop() {
  // Type out this string letter by letter on the computer (assumes US-style
  // keyboard)
  DigiKeyboard.println("Hello Digispark!");
  for(byte i = 0; i < 10; i++) {
    a_val = analogRead(A_PIN);
    mapped = map(a_val, 475, 605, 0, 255); // with a 10k resistor
    mapped = constrain(mapped, 0, 255);
    DigiKeyboard.delay(5);
    DigiKeyboard.print(mapped); DigiKeyboard.print("  ");
    DigiKeyboard.delay(100);
    a_last = a_val;
  }
  DigiKeyboard.println(); 
  DigiKeyboard.delay(1000); 
  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
}

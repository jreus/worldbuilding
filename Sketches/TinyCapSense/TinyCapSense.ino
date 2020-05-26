/*
 * Capsense with an ATTINY85 Lily/Digispark
 * Connect SEND PIN to PIN 0 and RECV PIN to PIN 4
 */

#include <CapacitiveSensor.h>

#define CAP_SENS  0
#define CAP_SEND  3
#define LED_PIN   1

// 1M resistor between pins
// 100pF cap between CAP_SENS and GND
// add a capacitive sensor (wire, foil, conductive object) to pin CAP_SENS
CapacitiveSensor capsense = CapacitiveSensor(CAP_SEND, CAP_SENS);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  //Serial.begin(9600);
  // turn off autocalibrate on channel 1 - just as an example
  capsense.set_CS_AutocaL_Millis(0xFFFFFFFF);
  //capsense.set_CS_AutocaL_Millis(100);
}

void loop() {
  int mappedval = 0;
  long capval =  capsense.capacitiveSensor(30);
  //Serial.println(capval);
  if(capval > 1500) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(10);                             // arbitrary delay to limit data to serial port 
}

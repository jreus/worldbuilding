/*
 * Capsense with an ATTINY85 Lily/Digispark
 * VIBRO MOTOR ON PIN 4
 * CAPSENSE ON PIN 0 (SENSOR) / 1 (SEND)
 */

#include <CapacitiveSensor.h>

#define CAP_SENS  0
#define CAP_SEND  4
#define VIB_PIN   1

// 1M resistor between pins
// 100pF cap between CAP_SENS and GND
// add a capacitive sensor (wire, foil, conductive object) to pin CAP_SENS
CapacitiveSensor capsense = CapacitiveSensor(CAP_SEND, CAP_SENS);

void setup() {
  pinMode(VIB_PIN, OUTPUT);
  //Serial.begin(9600);
  // turn off autocalibrate on channel 1 - just as an example
  capsense.set_CS_AutocaL_Millis(0xFFFFFFFF);
  //capsense.set_CS_AutocaL_Millis(100);
}

void loop() {
  int mappedval = 0;
  long capval =  capsense.capacitiveSensor(30);
  mappedval = map(capval, 300, 1600, 0, 255);
  mappedval = constrain(mappedval, 0, 255);
  //Serial.println(capval);
  /*
  if(capval > 350) {
    digitalWrite(VIB_PIN, HIGH);
  } else {
    digitalWrite(VIB_PIN, LOW);
  }*/
  analogWrite(VIB_PIN, mappedval);
  /*
  digitalWrite(VIB_PIN, HIGH);
  delay(200);
  digitalWrite(VIB_PIN, LOW);
  delay(1000);
  */
  delay(10);                             // arbitrary delay to limit data to serial port 
}

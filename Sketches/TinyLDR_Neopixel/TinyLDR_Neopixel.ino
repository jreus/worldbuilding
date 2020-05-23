/* 
 *  Use a LDR to control the blinking speed
 *  of a RGB neopixel using an ATTINY86 Lilypad / DigiSpark board
 *    Connect pin 0 to the neopixel data input pin
 *    Connect the analog sensor signal to pin 3
 */

#include <Adafruit_NeoPixel.h>

#define PIX_PIN           0   // neopixel data pin
#define AN_PIN            3   // analog sensor input pin
#define NUM_PIXELS        1   // number of neopixels attached

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIX_PIN, NEO_RGB + NEO_KHZ800);

void setup() {  
  pinMode(AN_PIN, INPUT);
  pixels.begin();
}

int speed_ms = 100; // global variable for blink speed

void loop() {
  int analog_value;
  analog_value = analogRead(AN_PIN);
  delay(2); // quick delay for stability

  // map/constrain the analog value to a delay time in ms
  speed_ms = constrain(map(analog_value, 447, 605, 50, 1000), 50, 1000);

  // red
  pixels.setColor(0, pixels.Color(255,0,0));
  pixels.show();

  delay(speed_ms);

  // blue
  pixels.setColor(0, pixels.Color(0,255,0));
  pixels.show();

  delay(speed_ms);

  // green
  pixels.setColor(0, pixels.Color(0,0,255));
  pixels.show();

  delay(speed_ms);
}

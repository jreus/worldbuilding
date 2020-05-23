/*
 * Control LED with Light Sensor
 * Control Vibro Motor with Switch
 * 
 * Connect analog sensor to A1 (PIN 2), switch to PIN 1
 * connect PIN 3 to the data pin of the neopixel, connect PIN 0 to the
 * red wire of the vibro motor.
 */

#include <Adafruit_NeoPixel.h>

#define VIB_PIN       1
#define SWITCH_PIN    0
#define LDR_PIN       A1      // PIN 2, aka analog1
#define PIXEL_PIN     3
#define NUM_PIXELS    1       // number of neopixels attached

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIXEL_PIN, NEO_RGB + NEO_KHZ800);

void setup() {  
  pinMode(VIB_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pixels.begin(); // initializes the neopixel data pin

  // Do a little test of the Neopixel colors
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show();
  delay(500);
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.show();
  delay(500);
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.show();
  delay(500);
  pixels.setPixelColor(0, 0);
  pixels.show();  
  delay(500);
}

void loop() {
  int analog_value, switch_value;
  int red, green, blue;
  analog_value = analogRead(LDR_PIN);
  delay(5);
  switch_value = digitalRead(SWITCH_PIN);
  delay(5); // quick delay for stability

  if(switch_value == 1) {
    digitalWrite(VIB_PIN, 1); 
  } else {
    digitalWrite(VIB_PIN, 0);     
  }

  // map red green blue values depending on light level
  // analog input is somewhere between 380 (darkness) and 700 (bright light), but you can play with these values
  // flipping the values reverses the mapping, so that 700 maps to 0 and 380 maps to 255
  red = constrain(map(analog_value, 380, 700, 0, 255), 0, 255);    // red is on in full light and off in darkness
  blue = constrain(map(analog_value, 700, 380, 0, 255), 0, 255);   // blue and green light up in darkness
  green = constrain(map(analog_value, 700, 380, 0, 255), 0, 255);

  pixels.setPixelColor(0, pixels.Color(red, blue, green));
  pixels.show();

  delay(20);
}

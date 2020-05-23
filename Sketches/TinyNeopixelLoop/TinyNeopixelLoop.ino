/* 
 *  Control a single Neopixel from a Lilypad ATTINY85 / DigiSpark board.
 *  
 *  Connect pin 0 to the digital input pin on the neopixel.
 *  And provide +5V/GND to the power pins on the neopixel.
 */

// Import the Neopixel library
#include <Adafruit_NeoPixel.h>
#import <math.h>

#define PIX_PIN           0   // neopixel pin
#define NUM_PIXELS        1   // the number of neopixels attached, increase this if you chain a few of them together

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIX_PIN, NEO_RGB + NEO_KHZ800);

void setup() {  
  pixels.begin();
}

void loop() {
  int i; // a counter variable we will use in the for loop
  
  pixels.setPixelColor(0, 0); // send command to turn off pixel 0
  pixels.show(); // update the pixel display with your commands


  // Fade in red with a for loop. i counts from 0-255
  for(i=0; i<=255; i++) {
    pixels.setPixelColor(0, pixels.Color(i, 0, 0));
    pixels.show();
    delay(1); // a tiny delay
  }


  // Fade in green, keep red at 255
  for(i=0; i<=255; i++) {
    pixels.setPixelColor(0, pixels.Color(255, i, 0));
    pixels.show();
    delay(1);
  }

  // Fade in blue, keep red and green at 255
  for(i=0; i<=255; i++) {
    pixels.setPixelColor(0, pixels.Color(255, 255, i));
    pixels.show();
    delay(1);
  }
}

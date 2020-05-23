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
  pixels.setPixelColor(0, 0); // send command to turn off pixel 0
  pixels.show(); // update the pixel display with your commands

  // Tell the pixel at address 0 you want it to turn red (red, blue, green)
  // each color value goes from 0-255
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show(); // update the neopixel
  delay(500); // pause half a second

  // The same, but blue
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.show(); 
  delay(500);

  // The same, but green
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.show(); 
  delay(500);

  // Red + Green
  pixels.setPixelColor(0, pixels.Color(255, 255, 0));
  pixels.show(); 
  delay(500);

  // Red + Blue
  pixels.setPixelColor(0, pixels.Color(255, 0, 255));
  pixels.show(); 
  delay(500);

   // Green + Blue
  pixels.setPixelColor(0, pixels.Color(0, 255, 255));
  pixels.show(); 
  delay(500);
}

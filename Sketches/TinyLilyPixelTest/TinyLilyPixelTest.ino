/*
 *  Pin outs:

    All pins can be used as Digital I/O
    Pin 0 → I2C SDA, PWM (LED on Model B)
    Pin 1 → PWM (LED on Model A)
    Pin 2 → I2C SCK, Analog In
    Pin 3 → Analog In (also used for USB+ when USB is in use)
    Pin 4 → PWM, Analog (also used for USB- when USB is in use)
    Pin 5 → Analog In

 * 
 * 
 */

#include <Adafruit_NeoPixel.h>

#define PIX_PIN       4   // neopixel strip data channel
#define NUM_PIXELS    8   // number of neopixels attached

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIX_PIN, NEO_RGB + NEO_KHZ800);

void setup() {               
  pixels.begin();
  for(byte pix = 0; pix < NUM_PIXELS; pix++) { // blackout
    pixels.setPixelColor(pix, 0);
    pixels.show();
  }
}


void loop() {
  byte val=0, pix=0;
  for(pix = 0; pix < NUM_PIXELS; pix++) {
    // for each pixel
    for(val=0; val < 255; val++) { // red
      pixels.setPixelColor(pix, pixels.Color(0, val, 0));
      pixels.show();
      delay(1);
    }
    for(val=0; val < 255; val++) { // green
      pixels.setPixelColor(pix, pixels.Color(val, 0, 0));
      pixels.show();
      delay(1);
    }
    for(val=0; val < 255; val++) { // blue
      pixels.setPixelColor(pix, pixels.Color(0, 0, val));
      pixels.show();
      delay(1);
    }
    for(val=0; val < 255; val++) { // white
      pixels.setPixelColor(pix, pixels.Color(val, val, val));
      pixels.show();
      delay(1);
    }
  }
  for(pix=0; pix < NUM_PIXELS; pix++) {
    pixels.setPixelColor(pix, 0);
    pixels.show();
    delay(40);
  }
}

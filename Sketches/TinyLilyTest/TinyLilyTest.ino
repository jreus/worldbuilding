#include <Adafruit_NeoPixel.h>
#import <math.h>

#define VIB_PIN       0
#define BI_PIN        1   // built-in led
#define PIX_PIN       4   // neopixel strip data channel

#define NUM_PIXELS    8   // number of neopixels attached

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIX_PIN, NEO_RGB + NEO_KHZ800);

// the setup routine runs once when you press reset:
void setup() {               
  // initialize the digital pin as an output.
  pinMode(0, OUTPUT); // connect a vibro motor or other analog actuator
  pinMode(1, OUTPUT); //LED on ATTiny85 Lily and DigiSpark
  pixels.begin();
}

int resetval = 99;
int cnt = resetval;
int pwmval = 0.0;
int dir = -1;
int pix = 0;
int red = 0, green = 0, blue = 0;
int brightness = 1;

// the loop routine runs over and over again forever:
void loop() {
  pwmval = 255 - (log(cnt) * 53);
  analogWrite(1, (int)pwmval);
  analogWrite(0, (int)pwmval);
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUM_PIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    brightness = random(0, 2);
    red = random(0, 256) * brightness;
    green = random(0, 256) * brightness;
    blue = random(0, 256) * brightness;
    pixels.setPixelColor(i, pixels.Color(red, green, blue)); // dark
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  

  delay(15);
  cnt = cnt + dir;
  if(cnt < 1) {
    cnt = 1; dir = 1;
  }
  if(cnt > 99) {
    cnt = resetval; dir = -1;
  }
}

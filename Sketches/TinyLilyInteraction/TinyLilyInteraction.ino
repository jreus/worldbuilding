/* 
 Pin outs:
    All pins can be used as Digital I/O
    Pin 0 → MOSI, SDA, PWM0
    Pin 1 → MISO, PWM1
    Pin 2 → SCLK, SCL, ADC1
    Pin 3 → USB+, ADC3
    Pin 4 → USB-, ADC2, PWM4
    Pin 5 → RESET, ADC0

 */

#include <Adafruit_NeoPixel.h>
#import <math.h>

#define VIB_PIN           1   // vib motor / PWM and built-in led
#define PIX_PIN           0   // neopixel pin
#define AN_PIN            3   // one of the analog inputs

#define NUM_PIXELS        8   // number of neopixels attached

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIX_PIN, NEO_RGB + NEO_KHZ800);

void setup() {  
  pinMode(AN_PIN, INPUT);
  pinMode(VIB_PIN, OUTPUT);       // connect a vibro motor or other analog actuator
  pixels.begin();
}

int an_sig = 0;
int mapped = 0;
int lightvals[] = {0,0,0,0,0,0,0,0}; 
int r=0, g=0, b=0;
byte thresh = 80;

void loop() {
  byte pix=0;
  an_sig = analogRead(AN_PIN); // read analog sensor
  delay(2);
  mapped = constrain(map(an_sig, 475, 605, 0, 255), 0, 255); // using a 10k resistor
  
  for(pix=0; pix < NUM_PIXELS; pix++) {
    pixels.setPixelColor(pix, 0);
  }
  pixels.show();
  
  if(mapped > thresh) {
    for(pix=0; pix < NUM_PIXELS; pix++) {
      r = map(mapped, 0, 255, 255, 0);
      g = map(mapped, 0, 255, 0, 255);
      b = map(mapped, 0, 255, 0, 255);
      pixels.setPixelColor(pix, pixels.Color(r, g, b));
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(100);
    }
  }
  while(mapped > thresh) {
    an_sig = analogRead(AN_PIN); // read analog sensor
    delay(2);
    mapped = constrain(map(an_sig, 475, 605, 0, 255), 0, 255); // using a 10k resistor
    analogWrite(VIB_PIN, mapped);
    for(pix=0; pix < NUM_PIXELS; pix++) {
      r = map(mapped, 0, 255, 255, 0);
      g = map(mapped, 0, 255, 0, 255);
      b = map(mapped, 0, 255, 0, 255);
      pixels.setPixelColor(pix, pixels.Color(r, g, b));
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  
  delay(20);
}

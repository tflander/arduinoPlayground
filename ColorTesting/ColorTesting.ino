// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            1

const int numPixels = 4;
int intensity = 64;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

 if (intensity == 64) {
    intensity = 48;
 } else {
  intensity = 64;
 }
//  pixels.setPixelColor( 0, 255, 128, 0); // yellow
//  pixels.setPixelColor( 0, 255, 64, 0); // orange
  pixels.setPixelColor( 0, 255, intensity, 0); // orange
  pixels.show();
  
  delay(5000);
  intensity += 40;
    
}



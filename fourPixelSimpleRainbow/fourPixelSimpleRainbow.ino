// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      4

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 2000; // delay for half a second
int numColors = 7;
int colorIndex = 0;
int intensity = 255;
int pixelPos = 0;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

int paintAllPixels(int red, int green, int blue) {
  for (int i = 0; i < NUMPIXELS; ++i) {
    pixels.setPixelColor(i, pixels.Color(red, green, blue)); 
  }
}
int paint(int pos, int color) {
  if(color == 0) {
   paintAllPixels(intensity, intensity, intensity);     
  } else if (color == 2) {
   paintAllPixels(intensity, 0, 0);     
  } else if (color == 3) {
   paintAllPixels(intensity, intensity, 0);     
  } else if (color == 4) {
   paintAllPixels(0, intensity, 0);     
  } else if (color == 5) {
   paintAllPixels(0, intensity, intensity);     
  } else if (color == 6) {
   paintAllPixels(0, 0, intensity);         
  } else {
   paintAllPixels(0, 0, 0);     
  }
  
   int nextColor = color + 1;
   if(nextColor >= numColors) {
      return 0;
   }
   return nextColor;    
}

void loop() {

  colorIndex = paint(pixelPos, colorIndex);
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).
}

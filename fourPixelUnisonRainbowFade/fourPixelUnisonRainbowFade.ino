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

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, PIN, NEO_GRB + NEO_KHZ800);

int red = 0;
int green = 0;
int blue = 0;
int intensity = 0;
int redIncrementer = 0;
int greenIncrementer = 0;
int blueIncrementer = 0;
int shortDelayInMs = 30;
int longDelayInMs = 4000;

int isBlack() {
  return red == 0 && green == 0 && blue == 0;
}

int isRed() {
  return red == 255 & green == 0 && blue == 0;
}

int isYellow() {
  return red == 255 & green == 255 && blue == 0; // TODO: want green to be 128
}

int isGreen() {
  return red == 0 & green == 255 && blue == 0;
}

int isCyan() {
  return red == 0 & green == 255 && blue == 255;
}

int isBlue() {
  return red == 0 & green == 0 && blue == 255;
}

int isPurple() {
  return red == 255 & green == 0 && blue == 255;
}

int isWhite() {
  return red == 255 & green == 255 && blue == 255;
}

int isOrange() {
  return red == 255 & green == 64 && blue == 0;
}
void blackToRed() {
      redIncrementer = 1;
      greenIncrementer = 0;
      blueIncrementer = 0;
}

void redToYellow() {
      redIncrementer = 0;
      greenIncrementer = 1;
      blueIncrementer = 0;
}

void whiteToRed() {
      redIncrementer = 0;
      greenIncrementer = -1;
      blueIncrementer = -1;
}

void yellowToGreen() {
  green=255;
  redIncrementer = -1;
  greenIncrementer = 0;
  blueIncrementer = 0;
}

void greenToCyan() {
  redIncrementer = 0;
  greenIncrementer = 0;
  blueIncrementer = 1;
}

void cyanToBlue() {
  redIncrementer = 0;
  greenIncrementer = -1;
  blueIncrementer = 0;
}

void blueToPurple() {
  redIncrementer = 1;
  greenIncrementer = 0;
  blueIncrementer = 0;
}

void purpleToWhite() {
  redIncrementer = 0;
  greenIncrementer = 1;
  blueIncrementer = 0;
}

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  intensity = intensity + 1;
  if(intensity >= 255) {
    if(!isBlack() && !isWhite()) {
      delay(longDelayInMs);
    }
    intensity = 0;
    
    if (isBlack()) {
       blackToRed();
    } else if (isRed()) {
      redToYellow();
    } else if (isYellow()) {
      yellowToGreen();
    } else if (isGreen()) {
      greenToCyan();
    } else if (isCyan()) {
        cyanToBlue();
    } else if (isBlue()) {
       blueToPurple();
    } else if (isPurple()) {
      purpleToWhite();
    } else if (isWhite()) {
      whiteToRed();
    }
  }
  
  for (int counter = 0; counter < numPixels; ++counter) {
    pixels.setPixelColor( counter, red, green, blue);
  }
  pixels.show();
  
  if(isOrange() || isYellow()) {
    if(isYellow()) {
      for (int counter = 0; counter < numPixels; ++counter) {
        pixels.setPixelColor( counter, 255, 128, 0);
      }
      pixels.show();
    }
    delay(longDelayInMs);
  }
  
  red = red + redIncrementer;
  green = green + greenIncrementer;
  blue = blue + blueIncrementer;  
  
  delay(shortDelayInMs);
    
}



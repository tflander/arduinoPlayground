#include <Adafruit_NeoPixel.h>

int black[3] = {0, 0, 0};
int red[3] = {255, 0, 0};
int orange[3] = {255, 48, 0};
int yellow[3] = {255, 128, 0};
int lime[3] = {255, 255, 0};
int green[3] = {0, 255, 0};
int cyan[3] = {0, 255, 255};
int blue[3] = {0, 0, 255};
int purple[3] = {255, 0, 255};
int white[3] = {255, 255, 255};

int* rainbowColors[9] = {
  red, orange, yellow, lime,
  green, cyan, blue, purple, white  
};

int currentColor = 0;
int numColors = sizeof(rainbowColors)/sizeof(rainbowColors[0]);

#define PIN            1
const int numPixels = 4;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, PIN, NEO_GRB + NEO_KHZ800);

int nextColor(int previousColor) {
  int newColor = previousColor + 1;
  if (newColor >= numColors) {
    newColor = 0;
  }
  return newColor;
}

void setup() {
  
  pixels.begin();
}

void loop() {
  int colorIndex = currentColor;
  for (int counter = 0; counter < numPixels; ++counter) {
    int* color = rainbowColors[colorIndex];
    pixels.setPixelColor( counter, color[0], color[1], color[2]);
    colorIndex = nextColor(colorIndex);
  }
  pixels.show();
  delay(4000);
  currentColor = nextColor(currentColor);
}

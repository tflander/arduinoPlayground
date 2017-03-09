#include <Adafruit_NeoPixel.h>

#define PIN            1
const int numPixels = 4;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, PIN, NEO_GRB + NEO_KHZ800);

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

int currentColorIndex = 0;
int numColors = sizeof(rainbowColors)/sizeof(rainbowColors[0]);

int intensity = 0;
int shortDelayInMs = 30;
int longDelayInMs = 4000;

int currentColor[3] = {0,0,0};
int endColor[3] = {0,0,0};

int nextColor(int previousColor) {
  int newColor = previousColor + 1;
  if (newColor >= numColors) {
    newColor = 0;
  }
  return newColor;
}

void copyColor(int color[3], int dest[3]) {
    // memcpy(dest, color, sizeof(black) * sizeof(black[0]));
    dest[0] = color[0];
    dest[1] = color[1];
    dest[2] = color[2];
}

void stepFade(int currentColor[3], int endColor[3]) {
    for(int i = 0; i < 3; ++i) {
        if(currentColor[i] < endColor[i]) {
            currentColor[i] = currentColor[i] + 1;
        } else if (currentColor[i] > endColor[i]) {
            currentColor[i] = currentColor[i] - 1;
        }
    }
}

void initStartAndEndColors() {
  copyColor(rainbowColors[currentColorIndex], currentColor);
  copyColor(rainbowColors[nextColor(currentColorIndex)], currentColor);  
}
void setup() {
  initStartAndEndColors();
  pixels.begin();
}

void loop() {
  if(++intensity >= 255) {
      delay(longDelayInMs);
      currentColorIndex = nextColor(currentColorIndex);
      initStartAndEndColors();
      intensity = 0;
  }
  
  for (int counter = 0; counter < numPixels; ++counter) {
    pixels.setPixelColor( counter, currentColor[0], currentColor[1], currentColor[2]);
  }
  pixels.show();
  delay(shortDelayInMs);
  stepFade(currentColor, endColor);
}



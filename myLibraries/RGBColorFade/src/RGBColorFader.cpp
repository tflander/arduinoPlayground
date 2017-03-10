#include "RGBColorFader.hpp"
#include <iostream>
using namespace std;

FadingColor::FadingColor(RgbPixelColor &color, RgbPixelColor &endColor, int cyclesToProcess)
{
  this->color = new RgbPixelColor(color);
  this->endColor = new RgbPixelColor(endColor);
  this->remainingCyclesToProcess = cyclesToProcess;
}

FadingColor::~FadingColor()
{
  delete this->color;
  delete this->endColor;
}

void FadingColor::processCycle() {
  color->stepFadeTo(*endColor);
  --this->remainingCyclesToProcess;
}

int FadingColor::isFinished() {
  return this->remainingCyclesToProcess <= 0;
}

void showColor(RgbPixelColor &color)
{
  cout << color.getRed() << ",";
  cout << color.getGreen() << ",";
  cout << color.getBlue() << endl;
}

/*
int main()
{

  RgbPixelColor black = RgbPixelColor(0, 0, 0);
  RgbPixelColor red = RgbPixelColor(255, 0, 0);
  RgbPixelColor orange = RgbPixelColor(255, 48, 0);
  RgbPixelColor yellow = RgbPixelColor(255, 128, 0);
  RgbPixelColor lime = RgbPixelColor(255, 255, 0);
  RgbPixelColor green = RgbPixelColor(0, 255, 0);
  RgbPixelColor cyan = RgbPixelColor(0, 255, 255);
  RgbPixelColor blue = RgbPixelColor(0, 0, 255);
  RgbPixelColor purple = RgbPixelColor(255, 0, 255);
  RgbPixelColor white = RgbPixelColor(255, 255, 255);

  RgbPixelColor rainbowColors[9] = {
      red, orange, yellow, lime,
      green, cyan, blue, purple, white};

  cout << endl
       << "RgbPixelColor" << endl;
  RgbPixelColor currentColor = RgbPixelColor(black);
  int currentColorIndex = 0;
  int numColors = sizeof(rainbowColors) / sizeof(rainbowColors[0]);

  for (int colorIndex = 0; colorIndex < numColors; ++colorIndex)
  {
    cout << "===" << endl;
    for (int i = 0; i < 256; ++i)
    {
      showColor(currentColor);
      currentColor.stepFadeTo(rainbowColors[colorIndex]);
    }
  }
}
*/

/*
int currentColorIndex = 0;
int numColors = sizeof(rainbowColors) / sizeof(rainbowColors[0]);

int intensity = 0;
int shortDelayInMs = 30;
int longDelayInMs = 4000;

RgbPixelColor currentColor = RgbPixelColor(black);
RgbPixelColor endColor = RgbPixelColor(black);

int nextColor(int previousColor)
{
  int newColor = previousColor + 1;
  if (newColor >= numColors)
  {
    newColor = 0;
  }
  return newColor;
}

void initStartAndEndColors()
{
  currentColor = RgbPixelColor(rainbowColors[currentColorIndex]);
  endColor = RgbPixelColor(rainbowColors[nextColor(currentColorIndex)]);
}

void setup()
{
  initStartAndEndColors();
  pixels.begin();
}

void loop()
{

  if (++intensity >= 255)
  {
    delay(longDelayInMs);
    currentColorIndex = nextColor(currentColorIndex);
    initStartAndEndColors();
    intensity = 0;
  }

  for (int counter = 0; counter < numPixels; ++counter)
  {
    pixels.setPixelColor(counter, currentColor.getRed(), currentColor.getGreen(), currentColor.getBlue());
  }
  pixels.show();
  delay(shortDelayInMs);
  currentColor.stepFadeTo(endColor);
}
*/
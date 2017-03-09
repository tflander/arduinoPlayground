#include "RGBColorFader.hpp"
#include <iostream>
using namespace std;

NeoPixelColor::NeoPixelColor(int red, int green, int blue)
{
  this->red = red;
  this->green = green;
  this->blue = blue;
}

NeoPixelColor::NeoPixelColor(const NeoPixelColor &src)
{
  red = src.red;
  green = src.green;
  blue = src.blue;
}

int NeoPixelColor::getRed() { return red; }
int NeoPixelColor::getGreen() { return green; }
int NeoPixelColor::getBlue() { return blue; }

void NeoPixelColor::stepFadeTo(NeoPixelColor endColor)
{

  if (red > endColor.getRed())
    --red;
  if (green > endColor.getGreen())
    --green;
  if (blue > endColor.getBlue())
    --blue;
  if (red < endColor.getRed())
    ++red;
  if (green < endColor.getGreen())
    ++green;
  if (blue < endColor.getBlue())
    ++blue;
}

FadingColor::FadingColor(NeoPixelColor &color, NeoPixelColor &endColor, int cyclesToProcess)
{
  this->color = new NeoPixelColor(color);
  this->endColor = new NeoPixelColor(endColor);
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

void showColor(NeoPixelColor &color)
{
  cout << color.getRed() << ",";
  cout << color.getGreen() << ",";
  cout << color.getBlue() << endl;
}

int main()
{

  NeoPixelColor black = NeoPixelColor(0, 0, 0);
  NeoPixelColor red = NeoPixelColor(255, 0, 0);
  NeoPixelColor orange = NeoPixelColor(255, 48, 0);
  NeoPixelColor yellow = NeoPixelColor(255, 128, 0);
  NeoPixelColor lime = NeoPixelColor(255, 255, 0);
  NeoPixelColor green = NeoPixelColor(0, 255, 0);
  NeoPixelColor cyan = NeoPixelColor(0, 255, 255);
  NeoPixelColor blue = NeoPixelColor(0, 0, 255);
  NeoPixelColor purple = NeoPixelColor(255, 0, 255);
  NeoPixelColor white = NeoPixelColor(255, 255, 255);

  NeoPixelColor rainbowColors[9] = {
      red, orange, yellow, lime,
      green, cyan, blue, purple, white};

  cout << endl
       << "NeoPixelColor" << endl;
  NeoPixelColor currentColor = NeoPixelColor(black);
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

/*
int currentColorIndex = 0;
int numColors = sizeof(rainbowColors) / sizeof(rainbowColors[0]);

int intensity = 0;
int shortDelayInMs = 30;
int longDelayInMs = 4000;

NeoPixelColor currentColor = NeoPixelColor(black);
NeoPixelColor endColor = NeoPixelColor(black);

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
  currentColor = NeoPixelColor(rainbowColors[currentColorIndex]);
  endColor = NeoPixelColor(rainbowColors[nextColor(currentColorIndex)]);
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
#include "RgbPixelColor.hpp"

RgbPixelColor::RgbPixelColor(int red, int green, int blue)
{
  this->red = red;
  this->green = green;
  this->blue = blue;
}

RgbPixelColor::RgbPixelColor(const RgbPixelColor &src)
{
  red = src.red;
  green = src.green;
  blue = src.blue;
}

int RgbPixelColor::getRed() { return red; }
int RgbPixelColor::getGreen() { return green; }
int RgbPixelColor::getBlue() { return blue; }

void RgbPixelColor::stepFadeTo(RgbPixelColor endColor)
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

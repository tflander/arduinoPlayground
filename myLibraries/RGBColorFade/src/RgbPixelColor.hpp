#ifndef RGBPIXELCOLOR_HPP
#define RGBPIXELCOLOR_HPP

class RgbPixelColor
{

private:
  int red;
  int green;
  int blue;

public:
  RgbPixelColor(int red, int green, int blue);

  RgbPixelColor(const RgbPixelColor &src);

  int getRed();
  int getGreen();
  int getBlue();

  void stepFadeTo(RgbPixelColor endColor);
};

#endif
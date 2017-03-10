#ifndef RGBCOLORFADER_HPP
#define RGBCOLORFADER_HPP

#include "RgbPixelColor.hpp"

class FadingColor {
  private:
    RgbPixelColor* color;
    RgbPixelColor* endColor;
    int remainingCyclesToProcess;

  public:
    FadingColor(RgbPixelColor& color, RgbPixelColor& endColor, int cyclesToProcess);
    ~FadingColor();
    void processCycle();
    int isFinished();
};

#endif
#ifndef RGBCOLORFADER_HPP
#define RGBCOLORFADER_HPP

class NeoPixelColor
{

private:
  int red;
  int green;
  int blue;

public:
  NeoPixelColor(int red, int green, int blue);

  NeoPixelColor(const NeoPixelColor &src);

  int getRed();
  int getGreen();
  int getBlue();

  void stepFadeTo(NeoPixelColor endColor);
};

class FadingColor {
  private:
    NeoPixelColor* color;
    NeoPixelColor* endColor;
    int remainingCyclesToProcess;

  public:
    FadingColor(NeoPixelColor& color, NeoPixelColor& endColor, int cyclesToProcess);
    ~FadingColor();
    void processCycle();
    int isFinished();
};

#endif
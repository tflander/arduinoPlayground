#include <iostream>
#include <RGBColorFader.hpp>

int main()
{
  std::cout << "Hello Color - ";
  RgbPixelColor black = RgbPixelColor(0, 0, 0);
  std::cout << black.getRed();
}
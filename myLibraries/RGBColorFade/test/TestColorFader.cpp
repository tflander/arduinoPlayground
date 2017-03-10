#include <iostream>
#include <RGBColorFader.hpp>

int main()
{
  std::cout << "Hello World!";
  NeoPixelColor black = NeoPixelColor(0, 0, 0);
  std::cout << black.getRed();
}
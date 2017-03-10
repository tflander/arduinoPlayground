add_library (RGBColorFade RGBColorFader.cpp)
add_library (RgbPixelColor RgbPixelColor.cpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
# target_include_directories (Hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable (faderTests TestColorFader.cpp)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (faderTests LINK_PUBLIC RGBColorFade RgbPixelColor)

include_directories("${CMAKE_SOURCE_DIR}/include")

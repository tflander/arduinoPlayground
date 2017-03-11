# CMake generated Testfile for 
# Source directory: /common/workspaces/arduino/myLibraries/RGBColorFade
# Build directory: /common/workspaces/arduino/build/RGBColorFade
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(RgbPixelColorTest "RgbPixelColorTest")
subdirs("src")
subdirs("test")
subdirs("demo")
subdirs("lib/googletest")

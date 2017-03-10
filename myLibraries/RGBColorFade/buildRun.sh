cd ../../build/RGBColorFade
cmake -G "Xcode" ../../myLibraries/RGBColorFade
xcodebuild
./test/Debug/faderTests

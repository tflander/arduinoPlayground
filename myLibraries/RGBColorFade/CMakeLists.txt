# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)

set(PROJECT_NAME RGBColorFade)
project(${PROJECT_NAME})

add_subdirectory (src)
add_subdirectory (test)
add_subdirectory (demo)
add_subdirectory(lib/googletest)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories("${CMAKE_SOURCE_DIR}/include")

cxx_test(RgbPixelColorTest gtest_main)

cmake_minimum_required(VERSION 3.10)
project(CalculatorTestTask)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

enable_testing() # Add this line to enable CTest

add_subdirectory(tests)

file(GLOB SOURCES "src/*.cpp")
add_executable(CalculatorTestTask ${SOURCES})

set(GTEST_DISCOVER_TESTS_DEBUG_MODE 1)
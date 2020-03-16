cmake_minimum_required(VERSION 3.10)
project(2_TestabilityIssues)

set(CMAKE_CXX_STANDARD 14)

#Add the google test subdirectory
add_subdirectory(./lib/googletest)

#include googletest/include dir
include_directories(./lib/googletest/googletest/include)

#include the googlemock/include dir
include_directories(./lib/googletest/googlemock/include)

add_executable(2_TestabilityIssues main.cpp)

#Link with GoogleTest
target_link_libraries(2_TestabilityIssues gtest gtest_main)

#Link with GoogleMock
target_link_libraries(2_TestabilityIssues gmock gmock_main)
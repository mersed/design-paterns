cmake_minimum_required(VERSION 3.10)
project(5_BuilderFacets)

set(CMAKE_CXX_STANDARD 14)

add_executable(5_BuilderFacets main.cpp Person.cpp PersonBuilder.cpp)
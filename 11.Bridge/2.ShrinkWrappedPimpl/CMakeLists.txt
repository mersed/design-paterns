cmake_minimum_required(VERSION 3.10)
project(2_ShrinkWrappedPimpl)

set(CMAKE_CXX_STANDARD 14)

add_executable(2_ShrinkWrappedPimpl main.cpp Pimpl.cpp Foo.cpp)
cmake_minimum_required(VERSION 3.10)
project(4_PrototypeViaSerialization)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lboost_serialization")
find_package(Boost 1.65.1 COMPONENTS serialization REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(4_PrototypeViaSerialization main.cpp)
    target_link_libraries(4_PrototypeViaSerialization ${Boost_LIBRARIES})
endif()
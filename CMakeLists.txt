cmake_minimum_required(VERSION 3.6)
project(Triangle_Calculator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(Triangle_Calculator ${SOURCE_FILES})
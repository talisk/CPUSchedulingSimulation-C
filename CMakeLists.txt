cmake_minimum_required(VERSION 3.1)
project(CPUScheduling)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(CPUScheduling ${SOURCE_FILES} PCB.cpp PCB.h Schedule.cpp Schedule.h Global.h)
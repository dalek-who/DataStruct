cmake_minimum_required(VERSION 3.6)
project(3_20_ReColor)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Queue.c Queue.h)
add_executable(3_20_ReColor ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.6)
project(3_25_NOT_RECURSION)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c Stack.c Stack.h)
add_executable(3_25_NOT_RECURSION ${SOURCE_FILES})
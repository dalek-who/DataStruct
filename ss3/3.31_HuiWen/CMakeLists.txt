cmake_minimum_required(VERSION 3.6)
project(3_31_HuiWen)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Queue.h Queue.c Stack.c Stack.h)
add_executable(3_31_HuiWen ${SOURCE_FILES})
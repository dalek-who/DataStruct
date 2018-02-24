cmake_minimum_required(VERSION 3.6)
project(3_21_RPN)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Stack.h Stack.c)
add_executable(3_21_RPN ${SOURCE_FILES})
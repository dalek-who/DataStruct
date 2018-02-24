cmake_minimum_required(VERSION 3.7)
project(10_32_FlagSort)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Queue.h Queue.c)
add_executable(10_32_FlagSort ${SOURCE_FILES})
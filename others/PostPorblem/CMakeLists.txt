cmake_minimum_required(VERSION 3.7)
project(PostPorblem)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Queue.c Queue.h Stack.c Stack.h)
add_executable(PostPorblem ${SOURCE_FILES})
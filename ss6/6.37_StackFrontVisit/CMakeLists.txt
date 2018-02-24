cmake_minimum_required(VERSION 3.7)
project(6_37_StackFrontVisit)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Stack.h Stack.c Tree.h Tree.c)
add_executable(6_37_StackFrontVisit ${SOURCE_FILES})
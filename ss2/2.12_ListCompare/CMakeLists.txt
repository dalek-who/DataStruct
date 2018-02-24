cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c SqList_int.c SqList_int.h)
add_executable(untitled ${SOURCE_FILES})
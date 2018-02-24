cmake_minimum_required(VERSION 3.6)
project(2_11_Insert)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c SqList_int.h SqList_int.c)
add_executable(2_11_Insert ${SOURCE_FILES})
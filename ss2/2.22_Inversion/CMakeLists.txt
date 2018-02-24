cmake_minimum_required(VERSION 3.6)
project(2_22_Inversion)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c LinkList_int.c LinkList_int.h)
add_executable(2_22_Inversion ${SOURCE_FILES})
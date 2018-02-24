cmake_minimum_required(VERSION 3.6)
project(4_29_KMP)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c DoubleLinkList.h DoubleLinkList.c)
add_executable(4_29_KMP ${SOURCE_FILES})
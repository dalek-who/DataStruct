cmake_minimum_required(VERSION 3.6)
project(4_21_BasicOperation)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c LinkList.h LinkList.c)
add_executable(4_21_BasicOperation ${SOURCE_FILES})
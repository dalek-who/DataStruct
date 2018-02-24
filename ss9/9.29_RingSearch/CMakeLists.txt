cmake_minimum_required(VERSION 3.7)
project(9_29_RingSearch)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c LinkList.h LinkList.c)
add_executable(9_29_RingSearch ${SOURCE_FILES})
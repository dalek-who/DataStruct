cmake_minimum_required(VERSION 3.6)
project(2_19_DeletElem)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c LinkList_int.h LinkList_int.c)
add_executable(2_19_DeletElem ${SOURCE_FILES})
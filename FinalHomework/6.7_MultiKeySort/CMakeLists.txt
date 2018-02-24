cmake_minimum_required(VERSION 3.7)
project(6_7_MultiKeySort)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c LinkList.h LinkList.c)
add_executable(6_7_MultiKeySort ${SOURCE_FILES})
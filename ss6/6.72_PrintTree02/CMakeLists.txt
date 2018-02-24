cmake_minimum_required(VERSION 3.7)
project(6_72_PrintTree02)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Tree_ChildLinklist.h  Tree_ChildLinklist.c LinkList.c LinkList.h)
add_executable(6_72_PrintTree02 ${SOURCE_FILES})
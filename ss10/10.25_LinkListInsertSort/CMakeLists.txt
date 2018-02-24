cmake_minimum_required(VERSION 3.7)
project(10_25_LinkListInsertSort)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c LinkList.c LinkList.h)
add_executable(10_25_LinkListInsertSort ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.7)
project(5_27_MatrixAdd)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c CrossLinkList.c CrossLinkList.h)
add_executable(5_27_MatrixAdd ${SOURCE_FILES})
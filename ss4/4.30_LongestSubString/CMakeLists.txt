cmake_minimum_required(VERSION 3.6)
project(4_30_LongestSubString)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c SqList.c SqList.h)
add_executable(4_30_LongestSubString ${SOURCE_FILES})
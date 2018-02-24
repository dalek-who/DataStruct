cmake_minimum_required(VERSION 3.6)
project(5_20_DisplayPolynomial)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c HignDimArray.c HignDimArray.h LinkList.c LinkList.h)
add_executable(5_20_DisplayPolynomial ${SOURCE_FILES})
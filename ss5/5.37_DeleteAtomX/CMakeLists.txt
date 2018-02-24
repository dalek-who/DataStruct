cmake_minimum_required(VERSION 3.7)
project(5_37_DeleteAtomX)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Stack.h Stack.c Glist.h Glist.c)
add_executable(5_37_DeleteAtomX ${SOURCE_FILES})
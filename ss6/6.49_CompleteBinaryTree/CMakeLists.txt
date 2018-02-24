cmake_minimum_required(VERSION 3.7)
project(6_49_CompleteBinaryTree)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Queue.h Queue.c Tree.h Tree.c)
add_executable(6_49_CompleteBinaryTree ${SOURCE_FILES})
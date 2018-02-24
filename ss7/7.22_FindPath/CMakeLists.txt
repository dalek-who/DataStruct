cmake_minimum_required(VERSION 3.7)
project(7_14_CreatGraph)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Graph_NeighborLinkList.h Graph_NeignborLinklist.c LinkList.h LinkList.c)
add_executable(7_14_CreatGraph ${SOURCE_FILES})
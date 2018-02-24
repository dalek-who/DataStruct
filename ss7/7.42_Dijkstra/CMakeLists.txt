cmake_minimum_required(VERSION 3.7)
project(7_42_Dijkstra)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c LinkList.c LinkList.h Graph_NeignborLinklist.c Graph_NeighborLinkList.h)
add_executable(7_42_Dijkstra ${SOURCE_FILES})
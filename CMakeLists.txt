cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c test.c)

add_executable(main main.c)
add_executable(test test.c)
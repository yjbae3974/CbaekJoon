cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c 2609.c 2748.c 5565.c)

add_executable(main main.c)
add_executable(test 2609.c)
add_executable(2748 2748.c)
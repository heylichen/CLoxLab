cmake_minimum_required(VERSION 3.22)
project(CLoxLab)

set(CMAKE_C_STANDARD 17)

add_executable(CLoxLab main.c chunk.c chunk.h debug.c debug.h memory.h memory.c value.h value.c vm.h vm.c)
cmake_minimum_required(VERSION 3.22)
project(CLoxLab)

set(CMAKE_C_STANDARD 17)

add_executable(CLoxLab main.c)
add_library(chunk chunk.c)
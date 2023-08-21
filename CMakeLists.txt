cmake_minimum_required(VERSION 3.26)
project(GigaChip8 C)

set(CMAKE_C_STANDARD 99)

add_executable(GigaChip8 main.c
        CPU.h
        CPU.c
        Memory.h
        Memory.c
)

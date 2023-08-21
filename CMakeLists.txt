cmake_minimum_required(VERSION 3.26)
project(GigaChip8 C)

set(CMAKE_C_STANDARD 99)

add_executable(GigaChip8 main.c
        include/CPU.h
        CPU.c
        include/Memory.h
        Memory.c
)

cmake_minimum_required(VERSION 3.26)
project(GigaChip8 C)

set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(GigaChip8 main.c
        include/CPU.h
        src/CPU.c
        include/Memory.h
        src/Memory.c
)

target_link_libraries(GigaChip8 ${SDL2_LIBRARIES})
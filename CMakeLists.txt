cmake_minimum_required(VERSION 3.27)
project(TAD_DLL C)

set(CMAKE_C_STANDARD 11)

add_executable(TAD_DLL main.c
        DLL.c
        DLL.h)

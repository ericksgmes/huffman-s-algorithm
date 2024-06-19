cmake_minimum_required(VERSION 3.28)
project(algoritmoHuffman C)

set(CMAKE_C_STANDARD 11)

add_executable(algoritmoHuffman main.c
        freq_table.c
        freq_table.h)

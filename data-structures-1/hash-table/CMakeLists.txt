cmake_minimum_required(VERSION 3.12)
project(TabelaHash C)

set(CMAKE_C_STANDARD 11)

add_executable(TabelaHash main.c hash.c hash.h)
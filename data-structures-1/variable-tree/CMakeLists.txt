cmake_minimum_required(VERSION 3.12)
project(ArvVar C)

set(CMAKE_C_STANDARD 11)

add_executable(ArvVar main.c arvvar.c arvvar.h)
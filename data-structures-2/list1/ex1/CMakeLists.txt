cmake_minimum_required(VERSION 3.17)
project(ex1 C)

set(CMAKE_C_STANDARD 11)

add_executable(ex1 main.c primeNumber.c primeNumber.h primeNumberInt.c primeNumberInt.h primeNumberBool.c primeNumberBool.h primeNumberBit.c primeNumberBit.h bitmap.c bitmap.h)
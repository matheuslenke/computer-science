cmake_minimum_required(VERSION 3.17)
project(ex1 C)

set(CMAKE_C_STANDARD 11)

add_executable(ex1 main.c bst.c bst.h pilha.c pilha.h lista.c lista.h)
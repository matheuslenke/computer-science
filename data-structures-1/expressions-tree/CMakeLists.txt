cmake_minimum_required(VERSION 3.12)
project(Arvore_expressoes C)

set(CMAKE_C_STANDARD 11)

add_library(Arvore_expressoes arv_exp.c arv_exp.h main.c)
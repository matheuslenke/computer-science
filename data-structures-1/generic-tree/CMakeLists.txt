cmake_minimum_required(VERSION 3.15)
project(ArvoreGen C)

set(CMAKE_C_STANDARD 11)

add_executable(ArvoreGen main.c arv_gen.c arv_gen.h Arv_exp_gen.c Arv_exp_gen.h)
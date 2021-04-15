cmake_minimum_required(VERSION 3.15)
project(Tad_Generica C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Tad_Generica
        listaGenerica.c
        listaGenerica.h
        lpontos.c
        lpontos.h
        main.c)

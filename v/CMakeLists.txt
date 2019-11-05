cmake_minimum_required(VERSION 3.14)
project(v C)

set(CMAKE_C_STANDARD 99)

add_executable(v main.c categoria.c categoria.h inserir.c inserir.h menu.c menu.h remover.c remover.h user.c user.h)
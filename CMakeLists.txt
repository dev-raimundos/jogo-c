cmake_minimum_required(VERSION 3.28)
project(Trabalho C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Trabalho
        acaoPersonagem.h
        main.c
        personagem.c
)

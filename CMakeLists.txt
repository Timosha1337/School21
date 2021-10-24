cmake_minimum_required(VERSION 3.20)
project(libf C)

set(CMAKE_C_STANDARD 11)

add_executable(libf
        main.c libft.h)

cmake_minimum_required(VERSION 3.20)
project(libf C)

set(CMAKE_C_STANDARD 11)
aux_source_directory(sourc/ SOURCE)
add_executable(libf
        main.c sourc/libft.h ${SOURCE})

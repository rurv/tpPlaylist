cmake_minimum_required(VERSION 4.0)
project(tpPlaylist C)

set(CMAKE_C_STANDARD 11)

add_executable(tpPlaylist main.c
        morceau.c
        morceau.h
        playlist.c
        playlist.h
        ihm.c
        ihm.h)

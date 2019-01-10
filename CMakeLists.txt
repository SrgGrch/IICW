cmake_minimum_required(VERSION 3.13)
project(II)

set(CMAKE_CXX_STANDARD 14)

include_directories(II)

add_executable(II
        II/Board.cpp
        II/Board.h
        II/GameSession.cpp
        II/GameSession.h
        II/Main.cpp
        II/Player.cpp
        II/Player.h
        II/Utils.h
        II/Word.h)

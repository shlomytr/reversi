cmake_minimum_required(VERSION 3.8)
project(ex1)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h Player.cpp Game.cpp Game.h Player.h GameLogic.cpp GameLogic.h HumanPlayer.cpp HumanPlayer.h DeafultLogic.cpp DeafultLogic.h)
add_executable(ex1 ${SOURCE_FILES})
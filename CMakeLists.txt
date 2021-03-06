cmake_minimum_required(VERSION 3.8)
project(reversi)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
set(CMAKE_CXX_STANDARD 98)
set(SOURCE_FILES src/Board.cpp src/DeafultLogic.cpp src/Game.cpp
        src/GameLogic.cpp src/HumanPlayer.cpp src/Player.cpp src/AIPlayer.cpp
        include/AIPlayer.h src/ConsolePrinter.cpp src/LocalPlayer.cpp
        src/RemotePlayer.cpp src/Client.cpp src/GameMode.cpp)
set(TEST_FILES test/board_test.cpp test/player_test.cpp test/gameLogic_test.cpp src/AIPlayer.cpp include/AIPlayer.h src/ConsolePrinter.cpp include/ConsolePrinter.h src/LocalPlayer.cpp include/LocalPlayer.h src/RemotePlayer.cpp include/RemotePlayer.h)
add_executable(runMain main.cpp ${SOURCE_FILES} src/AIPlayer.cpp include/AIPlayer.h include/Printer.h src/Client.cpp include/Client.h)
add_executable(runUnitTests test/gtest_main.cpp ${TEST_FILES} ${SOURCE_FILES} src/AIPlayer.cpp include/AIPlayer.h)
target_link_libraries(runUnitTests gtest gtest_main)
add_test(runUnitTests runUnitTests)
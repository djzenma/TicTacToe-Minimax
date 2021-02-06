cmake_minimum_required(VERSION 3.17)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToe main.cpp headers/GameEngine.h sources/GameEngine.cpp headers/Board.h sources/Board.cpp sources/MiniMax.cpp headers/MiniMax.h headers/Move.h headers/Constants.h)
cmake_minimum_required(VERSION 3.15)
project(ChessViz)

set(CMAKE_CXX_STANDARD 14)
add_executable(ChessViz src/main.c src/board_print_plain.c src/board_print_plain.h src/board_read.c src/board_clear.c src/board_clear.h src/board_start.c src/board_start.h src/board_movement.c src/board_movement.h src/board.c src/board.h src/board_read.h)
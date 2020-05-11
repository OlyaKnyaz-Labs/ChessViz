ODIR = build/
OBJ = $(CC) -c $< -o $@ $(CFLAGS)
MKDIR_BUILD = mkdir -p build/src

CC=gcc
CFLAGS =  -Wall -Werror
SOURCES=src/main.cpp src/board_print_plain.cpp src/board_read.cpp src/board_clear.cpp  src/board_start.cpp src/board_movement.cpp

.PHONY:all clean

all:binary/WChess.exe clean



binary/WChess.exe: build/src/main.o build/src/board_read.o build/src/board_clear.o  build/src/board_start.o build/src/board_print_plain.o build/src/board.o
    mkdir -p binary
    $(CC) $^ -o $@ $(CFLAGS)

build/src/main.o: src/main.c src/board.h

    $(MKDIR_BUILD)
    $(OBJ)

build/src/board_print_plain.o: src/board_print_plain.c src/board_print_plain.h
    $(MKDIR_BUILD)
    $(OBJ)

build/src/board_start.o: src/board_start.c src/board_start.h
    $(MKDIR_BUILD)
    $(OBJ)

build/src/board_clear.o: src/board_clear.c src/board_clear.h
    $(MKDIR_BUILD)
    $(OBJ)

build/src/board.o: src/board.c src/board.h
    $(MKDIR_BUILD)
    $(OBJ)

build/src/board_read.o: src/board_read.c src/board_read.h
    $(MKDIR_BUILD)
    $(OBJ)
clean:
    rm build/src/.o
    rmdir  build/src
    rmdir  build
ODIR = build/
OBJ = $(CC) -c $< -o $@ $(CFLAGS)
MKDIR_BUILD = mkdir -p build/src

CC=gcc
CFLAGS =  -Wall -Werror
SOURCES=src/main.cpp src/board_print_plain.c src/board_read.c  src/board_movement.c	

.PHONY:all test clean

all:binary/WChess.exe test clean

test:binary/WChess_test.exe
    $<

binary/WChess.exe: build/src/main.o build/src/board_read.o  build/src/board_print_plain.o build/src/board.o
	mkdir -p binary
	$(CC) $^ -o $@ $(CFLAGS)

binary/WChess_test.exe: build/test/main.o build/test/test_module.o build/src/board_print_plain.o build/src/board_start.o build/src/board.o build/src/board_read.o
    mkdir -p binary
    $(CC) $^ -o $@ $(CFLAGS)

build/test/main.o: test/main.c thirdparty/ctest.h src/board.h test/test_module.h
        mkdir -p build/test
        $(OBJ) -I thirdparty -I src
build/test/test_module.o: test/test_module.c thirdparty/ctest.h src/board.h test/test_module.h
        mkdir -p build/test
        $(OBJ) -I thirdparty -I src

build/src/main.o: src/main.c src/board.h
	$(MKDIR_BUILD)
	$(OBJ)	

build/src/board_print_plain.o:src/board_print_plain.c src/board_print_plain.h
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
	rm build/src/*.o
	rmdir  build/src
	rmdir  build

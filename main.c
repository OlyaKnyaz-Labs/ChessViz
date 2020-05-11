//
// Created by Ольга on 11.05.2020.
//

#include "board.h"
#include "board_clear.h"
#include "board_print_plain.h"
#include "board_start.h"

int main()
{
    char brd[8][8];
    board_start(brd);

    while (1) {
        board_print(brd);
        board(brd);
    }
}
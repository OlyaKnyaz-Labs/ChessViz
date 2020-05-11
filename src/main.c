#include "board.h"

#include "board_print_plain.h"

int main()
{
    char brd[8][8];
    board_start(brd);

    while (1) {
        board_print(brd);
        board(brd);
    }
}

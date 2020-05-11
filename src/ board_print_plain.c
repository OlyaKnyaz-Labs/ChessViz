//
// Created by Ольга on 11.05.2020.
//

#include " board_print_plain.h"

#include "board_print_plain.h"
#include <stdio.h>

void board_print(char board[8][8])
{
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  A B C D E F G H\n");
}
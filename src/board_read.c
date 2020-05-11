//
// Created by Ольга on 11.05.2020.
//

#include "board_read.h"
#include "board.h"

#include "board_read.h"
#include <stdio.h>
#include <stdlib.h>

#include "board_read.h"
#include <stdio.h>
#include <stdlib.h>

void board_read(char str[])
{
    int flag;
    do {
        scanf("%6s", str);
        flag = (check_input(str));
        if (flag) {
            printf("Incorrect input, try again\n");
        }
    } while (flag);
}

int check_input(char str[])
{
    if (str[0] < 'a'  str[0] > 'h'  str[1] < '1'  str[1] > '8'
    str[2] != '-'  str[3] < 'a'  str[3] > 'h'  str[4] < '1'
    str[4] > '8' || str[5] != '\0') {
        return 1;
    }

    else {
        return 0;
    }
}
void reformat_input(char input[], int move[4])
{
    char border = 8; //граница
    move[0] = input[0] - 'a';
    move[1] = border - (input[1] - '0');
    move[2] = input[3] - 'a';
    move[3] = border - (input[4] - '0');
}
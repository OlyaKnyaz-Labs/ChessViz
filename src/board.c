//
// Created by Ольга on 11.05.2020.
//

#include "board.h"
#include "board.h"

#include "board_read.h"
#include <stdio.h>
#include <stdlib.h>

void fig_move(char board[8][8], int move[])
{
    char temp = board[move[1]][move[0]];
    board[move[1]][move[0]] = ' ';
    board[move[3]][move[2]] = temp;
}
void board_start(char board[8][8])
{
    char reg = 32; //смена регистра СМЕНЯЕТ БУКВУ НА ЗАГЛАВНУЮ
    char fig[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    for (int j = 0; j < 8; ++j) {
        board[0][j] = fig[j];
        board[7][j] = fig[j] - reg;
        board[1][j] = 'p';
        board[6][j] = 'p' - reg;
        for (int i = 2; i < 6; ++i) {
            board[i][j] = ' ';
        }
    }
}
int check_move(char deck[8][8], int move[])
{
    switch (deck[move[1]][move[0]]) {
        case 'p':
            return pawn(deck, move, 0);
        case 'P':
            return pawn(deck, move, 1);
        case 'r':
            fig_move(deck, move);
            return 0;
        case 'R':
            fig_move(deck, move);
            return 0;
        case 'n':
            fig_move(deck, move);
            return 0;
        case 'N':
            fig_move(deck, move);
            return 0;
        case 'b':
            fig_move(deck, move);
            return 0;
        case 'B':
            fig_move(deck, move);
            return 0;
        case 'q':
            fig_move(deck, move);
            return 0;
        case 'Q':
            fig_move(deck, move);
            return 0;
        case 'k':
            fig_move(deck, move);
            return 0;
        case 'K':
            fig_move(deck, move);
            return 0;
        default:
            return 1;
    }
}

int pawn(char deck[8][8], int move[], char tm)
{
    if (tm == 1) {
        if ((move[2] == move[0] && deck[move[3]][move[2]] == ' '
             && (move[3] == move[1] - 1 || (move[1] == 6 && move[3] == 4)))
            || (move[3] == move[1] - 1
                && (move[2] == move[0] + 1 || move[2] == move[0] - 1)
                && deck[move[3]][move[2]] >= 'a'
                && deck[move[3]][move[2]] <= 'z')) {
            fig_move(deck, move);
            return 0;
        } else
            return 1;
    }
    if (tm == 0) {
        if ((move[2] == move[0] && deck[move[3]][move[2]] == ' '
             && (move[3] == move[1] + 1 || (move[1] == 1 && move[3] == 3)))
            || (move[3] == move[1] + 1
                && (move[2] == move[0] + 1 || move[2] == move[0] - 1)
                && deck[move[3]][move[2]] >= 'A'
                && deck[move[3]][move[2]] <= 'Z')) {
            fig_move(deck, move);
            return 0;
        } else
            return 1;
    }
    return 0;
}

void board(char deck[8][8])
{
    char* str = calloc(7, sizeof(char));
    int flag = 1;
    do {
        board_read(str);
        int move[4];
        reformat_input(str, move);

        flag = check_move(deck, move);
        if (flag) {
            printf("Incorrect turn, try again\n");
        }
    } while (flag);
    free(str);
}

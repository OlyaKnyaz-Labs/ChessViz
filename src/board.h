//
// Created by Ольга on 11.05.2020.
//

#ifndef CHESSVIZ_BOARD_H
#define CHESSVIZ_BOARD_H
int pawn(char deck[8][8], int move[], char tm);
void board(char deck[8][8]);
int check_move(char deck[8][8], int move[]);
void board_start(char board[8][8]);
#endif // CHESSVIZ_BOARD_H

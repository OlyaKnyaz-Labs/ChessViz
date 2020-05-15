//
// Created by Ольга on 15.05.2020.
//

#include "test_mod.h"
#include <board.h>
#include <board_read.h>
int main()
{
    CTEST(Syntax, Correct);
    CTEST(Syntax, Incorrect);
    CTEST(pawn, Correct);
    CTEST(pawn, Incorrect);
    CTEST(check_move, Correct);
    CTEST(check_move, Incorrect);
}
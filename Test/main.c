#include <board.h>
#include <board_read.h>
#include <ctest.h>
#include "test_mod.h"

int main()
{
    CTEST(Syntax, Correct);
    CTEST(Syntax, Incorrect);
    CTEST(pawn, Correct);
    CTEST(pawn, Incorrect);
    CTEST(check_move, Correct);
    CTEST(check_move, Incorrect);
}
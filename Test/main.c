//
// Created by Ольга on 15.05.2020.
//

#include "test_mod.h"
#include <board.h>
#include <board_read.h>
#include <board_start.h>

#include <ctest.h>
CTEST(Syntax, Correct)
{
int RES = check_input("b2-b5");
int OZH = 0;
ASSERT_EQUAL(OZH, RES);
}

CTEST(Syntax, Incorrect)
{
reformat_input( VVOD, HOD);
int RES = check_input("a2-a9");
int OZH = 1;
ASSERT_EQUAL(OZH, RES);
}

CTEST(pawn, Correct)
{
char deck[8][8];
board_start(deck);
char VVOD[] = "a7-a5";
int HOD[4];
int RES = pawn(deck, HOD, 0);
int OZH = 0;
ASSERT_EQUAL(OZH, RES);
}

CTEST(pawn, Incorrect)
{
char deck[8][8];
board_start(deck);
char VVOD[] = "a7-b6";
int HOD[4];
reformat_input( VVOD, HOD);
int RES = pawn(deck, HOD, 0);
int OZH = 1;
ASSERT_EQUAL(OZH, RES);
}

CTEST(check_move, Correct)
{
char deck[8][8];
board_start(deck);
char VVOD[] = "c7-c6";
int HOD[4];
reformat_input( VVOD, HOD);
int RES = check_move(deck, HOD);
int OZH = 0;
ASSERT_EQUAL(OZH, RES);
}

CTEST(check_move, Incorrect)
{
char deck[8][8];
board_start(deck);
char VVOD[] = "e5-e6";
int HOD[4];
reformat_input( VVOD, HOD);
int RES = check_move(deck, HOD);
int OZH = 1;
ASSERT_EQUAL(OZH, RES);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
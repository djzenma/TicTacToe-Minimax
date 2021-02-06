//
// Created by Mazen on 04.02.21.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <iostream>
#include <random>
#include "Constants.h"


class Board {
private:
    char board[DIM][DIM];

public:
    Board();

    char get(int x, int y);
    void set(int x, int y, char move);
    char** copy();

    void print(bool cellNumbers);

    bool anyWinnerDiagonal(char value);
    bool anyWinnerRow(char value);
    bool anyWinnerCol(char value);
    bool containsBlanc();
};


#endif //TICTACTOE_BOARD_H

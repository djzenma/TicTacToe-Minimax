//
// Created by Mazen on 05.02.21.
//

#ifndef TICTACTOE_MINIMAX_H
#define TICTACTOE_MINIMAX_H


#include <algorithm>
#include "Move.h"
#include "Constants.h"
#include "Board.h"

class MiniMax {
private:
    Board *board;

public:
    MiniMax();

    int scoreBoard();

    int minimax(bool maximizer);
    Move getOptimalMove(char** currentBoard);

    void updateBoard(char** boardCopy);
};


#endif //TICTACTOE_MINIMAX_H

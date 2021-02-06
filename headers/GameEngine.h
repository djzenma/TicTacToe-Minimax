//
// Created by Mazen on 04.02.21.
//

#ifndef TICTACTOE_GAMEENGINE_H
#define TICTACTOE_GAMEENGINE_H

#include <algorithm>

#include "Board.h"
#include "Move.h"
#include "MiniMax.h"


class GameEngine {
private:
    Board* board;
    MiniMax* miniMax;
    int turn;
    int winner;

    Move playerPlay();
    Move aiPlay();

    bool gameOver();

public:
    GameEngine();

    void run();
};


#endif //TICTACTOE_GAMEENGINE_H

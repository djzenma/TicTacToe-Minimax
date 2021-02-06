//
// Created by Mazen on 04.02.21.
//

#include "../headers/GameEngine.h"


GameEngine::GameEngine() {
    this->board = new Board();
    this->miniMax = new MiniMax();
}


// Checks whether someone won or is a draw
bool GameEngine::gameOver() {
    this->winner = IN_PROGRESS;

    // Player Won
    if(this->board->anyWinnerDiagonal(PLAYER_MOVE) ||
       this->board->anyWinnerRow(PLAYER_MOVE) ||
            this->board->anyWinnerCol(PLAYER_MOVE))
        this->winner = PLAYER;

    // AI Won
    else if(this->board->anyWinnerDiagonal(AI_MOVE) ||
            this->board->anyWinnerRow(AI_MOVE) ||
            this->board->anyWinnerCol(AI_MOVE))
        this->winner = AI;

    // Draw
    else if(!this->board->containsBlanc())
        this->winner = DRAW;

    return(this->winner != IN_PROGRESS);
}


void GameEngine::run() {
    Move move;

    std::cout << "*** Tic Tac Toe ***" << std::endl;
    std::cout << std::endl << "You " << PLAYER_MOVE << " AI " << AI_MOVE << std::endl << std::endl;
    this->board->print(true);

    this->turn = PLAYER;
    while (!this->gameOver()) {
        if(this->turn == PLAYER) {
            std::cout << "\nYour Turn " << std::endl;
            move = playerPlay();
            this->turn = AI;
        }
        else {
            std::cout << "\nAI played: " << std::endl;
            move = aiPlay();
            this->turn = PLAYER;
        }

        this->board->set(move.x, move.y, move.move);
        this->board->print(false);
    }

    if(this->winner == PLAYER)
        std::cout << "\nYOU WON!!" << std::endl;
    else if(this->winner == AI)
        std::cout << "\nYOU LOST :(" << std::endl;
    else
        std::cout << "\nIt is a DRAW..." << std::endl;
}

Move GameEngine::playerPlay() {
    int cellNum, x, y;

    do {
        std::cout << "Enter cell number: ";
        std::cin >> cellNum;
        cellNum--;
        x = cellNum / DIM;
        y = cellNum % DIM;
        if(x >= DIM || this->board->get(x, y) != BLANC)
            std::cout << "! Please enter a valid cell number (i.e., an empty one) !" << std::endl;
    } while (this->board->get(x, y) != BLANC);
    std::cout << "\nYou played: " << std::endl;

    Move move{
    .x = x,
    .y = y,
    .move = PLAYER_MOVE
    };
    return move;
}

Move GameEngine::aiPlay() {
    return this->miniMax->getOptimalMove(this->board->copy());
}

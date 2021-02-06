//
// Created by Mazen on 05.02.21.
//


#include "../headers/MiniMax.h"


MiniMax::MiniMax() {
    this->board = new Board();
}

// Score function for the board's status
int MiniMax::scoreBoard(){
    // Any Row victory?
    if(this->board->anyWinnerRow(AI_MOVE))
        return 10;
    else if (this->board->anyWinnerRow(PLAYER_MOVE))
        return -10;

    // Any Col victory?
    if(this->board->anyWinnerCol(AI_MOVE))
        return 10;
    else if (this->board->anyWinnerCol(PLAYER_MOVE))
        return -10;

    // Any Diagonal victory?
    if(this->board->anyWinnerDiagonal(AI_MOVE))
        return 10;
    else if (this->board->anyWinnerDiagonal(PLAYER_MOVE))
        return -10;

    // No win
    return 0;
}


// Minimax algorithm
int MiniMax::minimax(bool maximizer){
    int optimalScore;

    int score = scoreBoard();

    // Maximizer or Minimizer won
    if (score == 10 || score == -10)
        return score;

    // Draw
    if (!this->board->containsBlanc())
        return 0;

    // If Maximizer's turn
    if (maximizer){
        // initialize the optimal score
        optimalScore = -1000;

        // Exhaustive Search of all the cells
        for(int i = 0; i<DIM; i++) {
            for(int j = 0; j<DIM; j++) {
                // If empty cell
                if (this->board->get(i, j) == BLANC){
                    // Try a move in this cell
                    this->board->set(i, j, AI_MOVE);

                    // Calculate the score of making the move vs the current one
                    optimalScore = std::max(optimalScore, minimax(!maximizer));

                    // Undo the move in this cell
                    this->board->set(i, j, BLANC);
                }
            }
        }
    }

    // If Minimizer's turn
    else {
        optimalScore = 1000;

        // Exhaustive Search of all the cells
        for(int i = 0; i<DIM; i++) {
            for(int j = 0; j<DIM; j++) {
                // If empty cell
                if (this->board->get(i, j) == BLANC){
                    // Try a move in this cell
                    this->board->set(i, j, PLAYER_MOVE);

                    // Calculate the score of making the move vs the current one
                    optimalScore = std::min(optimalScore, minimax(!maximizer));

                    // Undo the move
                    this->board->set(i, j, BLANC);
                }
            }
        }
    }

    return optimalScore;
}

// Update the minimax board with the current board's status
void MiniMax::updateBoard(char** boardCopy) {
    for (int i = 0; i<DIM; i++)
        for (int j = 0; j<DIM; j++)
            this->board->set(i, j, boardCopy[i][j]);
}

// Returns the AI's optimal move
Move MiniMax::getOptimalMove(char** currentBoard){
    int optimalScore = -1000;
    Move optimalMove{
            .x= -1,
            .y= -1,
            .move = AI_MOVE
    };

    // Update the minimax board with the current board's status
    this->updateBoard(currentBoard);

    // Exhaustive Search of all possible moves
    for (int i = 0; i<DIM; i++){
        for (int j = 0; j<DIM; j++){
            // If empty cell
            if (this->board->get(i, j) == BLANC){
                // Try a move in this cell
                this->board->set(i, j, AI_MOVE);

                // Calculate minimax score of this move
                int score = minimax(false);

                // Undo the move
                this->board->set(i, j, BLANC);

                // if better move is found
                if (score > optimalScore){
                    optimalMove.x = i;
                    optimalMove.y = j;
                    optimalScore = score;
                }
            }
        }
    }

    return optimalMove;
}



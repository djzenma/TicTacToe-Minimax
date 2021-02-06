//
// Created by Mazen on 04.02.21.
//

#include "../headers/Board.h"


Board::Board() {
    // initialize the board to blanc
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            this->set(i, j, BLANC);
        }
    }
}


void Board::set(int x, int y, char move){
    this->board[x][y] = move;
}


char Board::get(int x, int y) {
    return this->board[x][y];
}

void Board::print(bool cellNumbers) {
    const std::string delim = std::string(10, '-');

    // print cell numbers and board values side by side
    for (int i = 0; i < DIM; i++) {
        // cell numbers
        for (int j = 0; j < DIM; j++) {
            std::cout << i * DIM + j + 1 << "\t";
        }
        // board values
        for (int j = 0; j < DIM; j++) {
            if(j==DIM-1)
                std::cout << this->board[i][j] << "\t";
            else
                std::cout << this->board[i][j] << " | ";
        }
        std::cout << std::endl << delim << "\t" << delim << std::endl;
    }
}

// checks whether there is a complete diagonal having all its cells as the passed value (X or O)
bool Board::anyWinnerDiagonal(const char value) {
    bool same = true;

    // check 1st diagonal
    for(int i=0; i<DIM; i++){
        if(this->get(i, i) != value) {
            same = false;
            break;
        }
    }
    if(same)
        return true;

    // check 2nd diagonal
    same = true;
    for(int i=0; i<DIM; i++){
        if(this->get(i, DIM-1-i) != value) {
            same = false;
            break;
        }
    }
    return same;
}

// checks whether there is a complete row having all its cells as the passed value (X or O)
bool Board::anyWinnerRow(const char value) {
    bool same;

    for(int i=0; i<DIM; i++){
        same = true;
        for(int j=0; j<DIM; j++) {
            if(this->get(i, j) != value) {
                same = false;
                break;
            }
        }
        if(same)
            return true;
    }
    return false;
}

// checks whether there is a complete column having all its cells as the passed value (X or O)
bool Board::anyWinnerCol(const char value) {
    bool same;

    for(int i=0; i<DIM; i++){
        same = true;
        for(int j=0; j<DIM; j++) {
            if(this->get(j, i) != value) {
                same = false;
                break;
            }
        }
        if(same)
            return true;
    }
    return false;
}


// checks whether there is a blanc cell in the board
bool Board::containsBlanc(){
    for (int i = 0; i<DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (this->get(i, j) == BLANC)
                return true;
        }
    }
    return false;
}

// creates & returns a copy of the current board
char** Board::copy() {
    char** copyBoard;
    copyBoard = new char*[DIM];

    for (int i = 0; i<DIM; i++) {
        copyBoard[i] = new char[DIM];
        for (int j = 0; j < DIM; j++)
            copyBoard[i][j] = this->get(i, j);
    }
    return copyBoard;
}

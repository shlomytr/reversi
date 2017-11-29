//
// Created by Shlomy and Omer
//

#include "../include/GameLogic.h"

GameLogic::GameLogic(Board *board) {
    this->board = board;
}


void GameLogic::move(bool blacksTurn, int row, int col) {
    bool foundATileToSwitch = false;
    for (int k = -1; k < 2; k++)
        for (int l = -1; l < 2; l++)
            if (k != 0 || l != 0) {
                if (changeBoard(blacksTurn, row, col, k, l, false) && !foundATileToSwitch) {
                    changeSingleTile(blacksTurn, row, col);
                    foundATileToSwitch = true;
                }
            }

}

void GameLogic::changeSingleTile(bool blacksTurn, int i, int j) {
    if (blacksTurn) {
        board->addToBTiles(1);
        board->setCell(i, j, 'x');
    } else {
        board->addToWTiles(1);
        board->setCell(i, j, 'o');
    }
}

void GameLogic::flipTile(bool blacksTurn, int i, int j) {
    if (blacksTurn) {
        board->addToWTiles(-1);
        board->addToBTiles(1);
        board->setCell(i, j, 'x');
    } else {
        board->addToBTiles(-1);
        board->addToWTiles(1);
        board->setCell(i, j, 'o');
    }
}

bool GameLogic::getPosCell(int i, int j) {
    return board->getPosCell(i, j);
}




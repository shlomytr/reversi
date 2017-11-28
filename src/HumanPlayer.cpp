//
// Created by Shlomy Trajber
// ID - 305626962
//

#include "../include/HumanPlayer.h"

HumanPlayer::HumanPlayer(GameLogic *logic1):Player(logic1){
    this->canPlay = true;
}

void HumanPlayer::playOneTurn(bool myTurn) {
    cout << "Please enter your next move: row,col\n";
    int row, col;
    char dummy;
    cin >> row >> dummy >> col;
    while (!logic->getPosCell(row - 1, col - 1)) {
        cout << "Invalid move, please enter a legal move: row,col\n";
        cin >> row >> dummy >> col;
    }
    lastMove.first = row - 1;
    lastMove.second = col - 1;
    logic->move(myTurn, row -1, col - 1);
}
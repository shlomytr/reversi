//
// Created by Shlomy and Omer
//

#include <limits>
#include "../include/HumanPlayer.h"

HumanPlayer::HumanPlayer(GameLogic *logic1, Printer *printer):Player(logic1){
    this->canPlay = true;
    this->type=1;
    this->printer = printer;
}

void HumanPlayer::playOneTurn(bool blacksTurn) {
    printer->printEnterNextTurn();
    int row, col;
    char dummy;
    while(true) {
        cin >> row >> dummy >> col;
        //if its invalid move.
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printer->PrintInvalidMove();
        } else
            break;
    }
    while (!logic->getPosCell(row - 1, col - 1)) {
        printer->PrintInvalidMove();
        cin >> row >> dummy >> col;
    }
    lastMove.first = row - 1;
    lastMove.second = col - 1;
    logic->move(blacksTurn, row -1, col - 1);
}
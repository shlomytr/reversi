//
// Created by Shlomy and Omer
//

#include "../include/Game.h"


using namespace std;


Game::Game(Board *board, Player *black, Player *white, GameLogic *logic, Printer *printer) {
    this->board = board;
    this->white = white;
    this->black = black;
    this->logic = logic;
    this->printer = printer;
    blacksTurn=true;
}

void Game::playGame() {

    // In the first turn there should not be a message of last position
    bool notFirstTurn = false;

    while (isGameNotOver()) {
        printer->printBoard(*board);
        if (blacksTurn) {
            if (notFirstTurn)
                printer->printLastMove(blacksTurn, white->getLastMove().first, white->getLastMove()
                        .second);
            notFirstTurn = true;
            printer->printNextTurn(blacksTurn);
            if (logic->possibleMoves(blacksTurn,black->getType(),printer))
                black->playOneTurn(blacksTurn);
             else {
                black->declareNoMoves();
                printer->printNoMoves();
            }
        } else {
            printer->printLastMove(blacksTurn, black->getLastMove().first, black->getLastMove().second);
            printer->printNextTurn(blacksTurn);
            if (logic->possibleMoves(blacksTurn,white->getType(), printer))
                white->playOneTurn(blacksTurn);
             else {
                white->declareNoMoves();
                printer->printNoMoves();
            }
        }
        blacksTurn = !blacksTurn;
    }

    printer->printsWhoWon(*board);
}



bool Game::isGameNotOver() {

    return (!board->isFull() && (black->getCanPlay() || white->getCanPlay()));
}






//
// Created by Shlomy and Omer
//

#include "../include/Game.h"


using namespace std;


Game::Game(Board *board, Player *black, Player *white, GameLogic *logic) {
    this->board = board;
    this->white = white;
    this->black = black;
    this->logic = logic;
    blacksTurn=true;
}

void Game::playGame() {

    // In the first turn there should not be a message of last position
    bool notFirstTurn = false;

    while (isGameNotOver()) {
        printBoard();
        if (blacksTurn) {
            if (notFirstTurn)
                printLastMove(white->getLastMove().first, white->getLastMove()
                        .second);
            notFirstTurn = true;
            printNextTurn();
            if (logic->possibleMoves(blacksTurn,1)) {
                black->setCanPlay(true);
                black->playOneTurn(blacksTurn);
            } else {
                black->setCanPlay(false);
                printNoMoves();
            }
        } else {
            printLastMove(black->getLastMove().first, black->getLastMove().second);
            printNextTurn();
            if (logic->possibleMoves(blacksTurn,white->getType())) {
                white->setCanPlay(true);
                white->playOneTurn(blacksTurn);
            } else {
                white->setCanPlay(false);
                printNoMoves();
            }
        }
        blacksTurn = !blacksTurn;
    }

    printsWhoWon();
}


void Game::printNextTurn() {

    if (blacksTurn)
        cout << "The next move - Player x:\n\n";
    else
        cout << "The next move - Player o:\n\n";
}

void Game::printNoMoves() {
    cout << "No possible moves, the turn goes to the next player. Press a key and then enter to continue\n";
    char k;
    cin >> k;
}

bool Game::isGameNotOver() {

    return (!board->isFull() && (black->getCanPlay() || white->getCanPlay()));
}

void Game::printsWhoWon() {
    cout << "The final board:\n";
    board->printBoard();
    cout << "The game is finished! The final score is: Black = " << board->getBTiles() << "\tWhite = "
         << board->getWTiles() << endl;
    cout << "The winner is ";
    if (board->getBTiles() > board->getWTiles())
        cout << "Black!\n";
    else if (board->getBTiles() < board->getWTiles())
        cout << "White!\n";
    else
        cout << "no one! The game ended as a draw!\n";


}

void Game::printLastMove(int i, int j) {
    if (!blacksTurn)
        cout << "The last move of player x was: (" << i + 1 << "," << j + 1 << ")\n";
    else
        cout << "The last move of player o was: (" << i + 1 << "," << j + 1 << ")\n";

}

void Game::printBoard() {
    cout << "The current board:\n";
    board->printBoard();
    cout << "The score is: Black = " << board->getBTiles() << "\tWhite = " << board->getWTiles() << endl;
}




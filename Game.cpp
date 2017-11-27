//
// Created by Shlomy Trajber
// ID - 305626962
//

#include "Game.h"


using namespace std;

Game::Game(Board *board, Player *black, Player *white, GameLogic *logic) {
    this->board = board;
    this->black = black;
    this->white = white;
    this->logic = logic;
}

void Game::playGame() {

    // Pair of ints for the input of the next move of the player

    pair<int, int> nextMove;

    // In the first turn there should not be a message of last position
    bool notFirstTurn = false;
    while (isGameNotOver()) {
        printBoard();
        if (blacksTurn) {
            if (notFirstTurn)
                printLastMove(nextMove.first, nextMove.second);
            notFirstTurn = true;
            printNextTurn();
            if (logic->possibleMoves(blacksTurn)) {
                black->setCanPlay(true);
                nextMove = enterNextMove();
                logic->move(blacksTurn, nextMove.first, nextMove.second);
            } else {
                black->setCanPlay(false);
                printNoMoves();
            }
        } else {
            printLastMove(nextMove.first, nextMove.second);
            printNextTurn();
            if (logic->possibleMoves(blacksTurn)) {
                white->setCanPlay(true);
                nextMove = enterNextMove();
                logic->move(blacksTurn, nextMove.first, nextMove.second);
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

pair<int, int> Game::enterNextMove() {
    cout << "Please enter your next move: row,col\n";
    int row, col;
    char dummy;
    cin >> row >> dummy >> col;
    while (board->getPosCell(row - 1, col - 1) == false) {
        cout << "Invalid move, please enter a legal move: row,col\n";
        cin >> row >> dummy >> col;
    }
    pair<int, int> ans = make_pair(row - 1, col - 1);
    return ans;
}







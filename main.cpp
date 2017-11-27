//
// Created by Shlomy Trajber
// ID - 305626962
//

#include <iostream>
#include "Board.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "DeafultLogic.h"


using namespace std;


int main() {
    Player b = HumanPlayer();
    Player *black = &b;
    cout<< "hellopooo\n";
    Player w = HumanPlayer();
    Player *white = &w;
    Board bo;
    cout<< "hellopooo\n";
    Board *board = &bo;
    DefaultLogic l = DefaultLogic(board);
    GameLogic *logic = &l;
    Game game(board, black, white, logic);
    game.playGame();


    return 0;
}
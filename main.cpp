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
    Player w = HumanPlayer();
    Board bo;
    DefaultLogic l = DefaultLogic(&bo);
    Game game(&bo, &b, &w, &l);
    game.playGame();

    return 0;
}
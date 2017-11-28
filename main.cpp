//
// Created by Shlomy Trajber
// ID - 305626962
//

#include <iostream>
#include "include/Board.h"
#include "include/Game.h"
#include "include/HumanPlayer.h"
#include "include/DeafultLogic.h"


using namespace std;


int main() {
    Board bo;
    DefaultLogic l = DefaultLogic(&bo);
    HumanPlayer b = HumanPlayer(&l);
    HumanPlayer w = HumanPlayer(&l);
    Game game(&bo, &b, &w, &l);
    game.playGame();

    return 0;
}
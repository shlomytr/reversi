//
// Created by Shlomy and Omer
//

#include <iostream>
#include "include/Board.h"
#include "include/Game.h"
#include "include/HumanPlayer.h"
#include "include/DeafultLogic.h"
#include "include/AIPlayer.h"


using namespace std;

Player * chooseGameMode(GameLogic &l, Board &board) {
    int ans;
    cout << "Hello and welcome to Reversi!\nTo play against a human player please enter 1\n"
            "To play against the computer please enter 2\n";
    cin >> ans;
    while (ans != 1 && ans != 2) {
        cout << "Invalid choice, please try again\n";
        cin >> ans;
    }
        if (ans ==1){
            Player *wh = new HumanPlayer(&l);
            return wh;
        }
        else if (ans ==2){
            Player *wh = new AIPlayer(&l,&board);
            return wh;
        }

}




int main() {
    Board bo(8);
    DefaultLogic l = DefaultLogic(&bo);
    HumanPlayer b = HumanPlayer(&l);
    Player *w  = chooseGameMode(l,bo);
    Game game(&bo, &b, w, &l);
    game.playGame();
    delete(w);
    return 0;
}
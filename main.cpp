//
// Created by Shlomy and Omer
//

#include <iostream>
#include "include/Board.h"
#include "include/Game.h"
#include "include/HumanPlayer.h"
#include "include/DeafultLogic.h"
#include "include/AIPlayer.h"
#include "include/ConsolePrinter.h"


using namespace std;

Player * chooseGameMode(GameLogic &l, Board &board, Printer &p) {
    int ans;
    cout << "Hello and welcome to Reversi!\nTo play against a human player please enter 1\n"
            "To play against the computer please enter 2\n";
    cin >> ans;
    while (ans != 1 && ans != 2) {
        cout << "Invalid choice, please try again\n";
        cin >> ans;
    }
        if (ans ==1){
            Player *wh = new HumanPlayer(&l,&p);
            return wh;
        }
        else if (ans ==2){
            Player *wh = new AIPlayer(&l,&board);
            return wh;
        }

}




int main() {
    Board bo(8);
    ConsolePrinter p = ConsolePrinter();
    DefaultLogic l = DefaultLogic(&bo);
    HumanPlayer b = HumanPlayer(&l,&p);
    Player *w  = chooseGameMode(l,bo, p);
    Game game(&bo, &b, w, &l, &p);
    game.playGame();
    delete(w);
    return 0;
}
//
// Created by Shlomy and Omer
//

#include <iostream>
#include <cstdlib>
#include "include/Board.h"
#include "include/Game.h"
#include "include/HumanPlayer.h"
#include "include/DeafultLogic.h"
#include "include/AIPlayer.h"
#include "include/ConsolePrinter.h"
#include "OnlinePlayer.h"


using namespace std;
/*

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
        else if (ans == 3){
        //connect to server and gets 1 for black and 2 for white to x
            if (x==1){
                LocalPlayer b = LocalPlayer(&l,&b);
                RemotePlayer w = RemotePlayer(&l,&b);
            }
            if (x==2){
                RemotePlayer b = RemotePlayer(&l,&b);
                LocalPlayer w = LocalPlayer(&l,&b);
            }
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
 */


    using namespace std;
    int main() {
        OnlinePlayer client("127.0.0.1", 8000);
        try {
            client.connectToServer();
        } catch (const char *msg) {
            cout << "Failed to connect to server. Reason:" << msg << endl;
            exit(-1);
        }
        int num1, num2;
        char op;
        int i = 0;
        while (i<3) {
            cout << "Enter an exercise (e.g., 15*19):";
            cin >> num1 >> op >> num2;
            cout << "Sending exercise: " << num1 << op
                 << num2 << endl;
            try {
                int result = client.sendExercise(num1,
                                                 op, num2);
                cout << "Result: " << result << endl;
            } catch (const char *msg) {
                cout << "Failed to send exercise to server. Reason: " << msg << endl;
            }
            i++;
        }
    }

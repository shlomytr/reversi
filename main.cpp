//
// Created by Shlomy and Omer
//

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include "include/Board.h"
#include "include/Game.h"
#include "include/HumanPlayer.h"
#include "include/DeafultLogic.h"
#include "include/AIPlayer.h"
#include "include/ConsolePrinter.h"
#include "include/Client.h"
#include "include/LocalPlayer.h"
#include "include/RemotePlayer.h"


using namespace std;


pair <Player *,Player *>  chooseGameMode(GameLogic &l, Board &board, Printer &p, Client &c, HumanPlayer &h) {
    int ans;
    pair<Player *, Player *> players;
    cout << "Hello and welcome to Reversi!\nTo play against a human player please enter 1\n"
            "To play against the computer please enter 2\nTo play against an online player please enter 3\n";
    cin >> ans;
    while (ans != 1 && ans != 2 && ans!=3) {
        cout << "Invalid choice, please try again\n";
        cin >> ans;
    }
        if (ans ==1){
            Player *wh = new HumanPlayer(&l,&p);
            players = make_pair(&h,wh);
        }
        else if (ans ==2){
            Player *wh = new AIPlayer(&l,&board);
            players = make_pair(&h,wh);
        }

        else if (ans == 3){
            try {
                c.connectToServer();
            } catch (const char *msg) {
                cout << "Failed to connect to server. Reason:" << msg << endl;
                exit(-1);
            }
            cout<<"Waiting for the other player to connect...\n";
            int order;
        //connect to server and gets 1 for black and 2 for white into order
            int n = read(c.getClientSocket(), &order, sizeof(int));
            if(n == -1) {
                cout << "Error reading the turn of the player";
                exit (-1);
            }
            if (order==1){
                LocalPlayer *b = new LocalPlayer(&l,&h,&c);
                RemotePlayer *w = new RemotePlayer(&l,&c);
                players.first=b;
                players.second=w;
            }
            if (order==2){
                RemotePlayer *b =new RemotePlayer(&l,&c);
                LocalPlayer *w =new LocalPlayer(&l,&h,&c);
                players.first=b;
                players.second=w;
            }
        }
    return players;

}




int main() {

    Board board(4);
    ConsolePrinter printer = ConsolePrinter();
    Client client;
    DefaultLogic logic = DefaultLogic(&board);
    HumanPlayer *humanPlayer = new HumanPlayer(&logic,&printer);
           // HumanPlayer(&logic,&printer);
    pair <Player *, Player *> players = chooseGameMode(logic,board, printer, client,*humanPlayer);
    Game game(&board, players.first, players.second, &logic, &printer);
    game.playGame();
    delete(players.first);
    delete(players.second);
    delete(humanPlayer);
    return 0;
}


/*
    using namespace std;
    int main() {
        Client client(NULL, "127.0.0.1", 8000);
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
*/
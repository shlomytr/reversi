//
// Created by Shlomy and Omer
//

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <cstring>
#include "include/Board.h"
#include "include/Game.h"
#include "include/HumanPlayer.h"
#include "include/DeafultLogic.h"
#include "include/AIPlayer.h"
#include "include/ConsolePrinter.h"
#include "include/Client.h"



using namespace std;

void sendToServer (pair <Player *,Player *> players, Client &c){
    cout<<"Please choose one of the following:\n'start <name>' to start a game with a name of 'name'\n"
            "'list_games' to get the current joinable games\n'join <name>' to join a game with a name of 'name'\n";
    string m;
    cin>>m;
    int size= (int) m.size();
    char message [size];
    bool stopped = false;
    while(!stopped){
        while (strncmp(message,"start", sizeof("start")) !=0  && strncmp(message,"join", sizeof("join")) !=0
               && strcmp(message, "list_games") != 0){
            cout<<"Invalid input. Please try again";
            cin>>m;
            size= (int) m.size();
            message [size];
        }
        int sizeRec = 0;
        int n = write(c.getClientSocket(), message, sizeof(message));
        if(n == -1) {
            cout << "Error writing the the message to the server";
            exit (-1);
    }
        if (strcmp(message, "list_games") == 0) {
            n = read(c.getClientSocket(), &sizeRec, sizeof(sizeRec));
            if(n == -1) {
                cout << "Error reading the size of the message from the server";
                exit(-1);
            }
            char input [sizeRec];
            n= read(c.getClientSocket(), &input, sizeof(input) );
            if(n == -1) {
                cout << "Error reading the message from the server";
                exit(-1);
            }
            cout<<input<<endl;
        }

    stopped=!stopped;
}


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



//            cout<<"Waiting for the other player to connect...\n";
//            int order;
//        //connect to server and gets 1 for black and 2 for white into order
//            int n = read(c.getClientSocket(), &order, sizeof(int));
//            if(n == -1) {
//                cout << "Error reading the turn of the player";
//                exit (-1);
//            }
//            if (order==1){
//                LocalPlayer *b = new LocalPlayer(&l,&h,&c);
//                RemotePlayer *w = new RemotePlayer(&l,&c);
//                players.first=b;
//                players.second=w;
//            }
//            if (order==2){
//                RemotePlayer *b =new RemotePlayer(&l,&c);
//                LocalPlayer *w =new LocalPlayer(&l,&h,&c);
//                players.first=b;
//                players.second=w;
//            }
        }
    return players;

}




int main() {

    Board board(8);
    ConsolePrinter printer = ConsolePrinter();
    int port;
    char ip[9];
    ifstream objectFile("../clientConfig.txt");
    if(!objectFile) {
        cout << "Error reading network configuration file";
        exit(-1);
    }
    objectFile >> port >> ip ;
    objectFile.close();
    try {
    Client client(ip, port);
    DefaultLogic logic = DefaultLogic(&board);
    HumanPlayer *humanPlayer = new HumanPlayer(&logic,&printer);
    pair <Player *, Player *> players = chooseGameMode(logic,board, printer, client,*humanPlayer);
    Game game(&board, players.first, players.second, &logic, &printer);
    game.playGame();
    delete(players.first);
    delete(players.second);
    if(players.first->getType() == 3 || players.second->getType() == 3)
        delete(humanPlayer);
    } catch (const char *msg) {
        cout << "Error: " << msg << endl;
        exit(-1);
    }
    return 0;
}
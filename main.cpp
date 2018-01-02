//
// Created by Shlomy and Omer
//

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <cstring>
#include <sstream>
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

void sendToServer (pair <Player *,Player *> &players, GameLogic &l, Board &board, Client &c, HumanPlayer &h) {
    cout << "Please choose one of the following:\n'start <name>' to start a game with a name of 'name'\n"
            "'list_games' to get the current joinable games\n'join <name>' to join a game with a name of 'name'\n";

    string message;
    cin.ignore();
    getline(cin,message);
    int size = (int) message.size();
    string command;
    command =  message.substr(0, message.find(" "));
    cout << command << endl;
    bool stopped = false;
    while (!stopped) {
        while (command != "start" && command != "join" && command != "list_games") {
            cout << "Invalid input. Please try again\n";

            getline(cin,message);
            size = (int) message.size();
            command =  message.substr(0, message.find(" "));
        }
        try {
            c.connectToServer();
        } catch (const char *msg) {
            cout << "Failed to connect to server. Reason:" << msg << endl;
            exit(-1);
        }
        int intRec = 0;
        int n = write(c.getClientSocket(), message.c_str(), sizeof(message));
        if (n == -1) {
            cout << "Error writing the the message to the server";
            exit(-1);
        }
        if (command == "list_games") {
            n = read(c.getClientSocket(), &intRec, sizeof(intRec));
            if (n == -1) {
                cout << "Error reading the size of the message from the server";
                exit(-1);
            }
            if(intRec) {
                char input[intRec];
                bzero((char *)input, intRec*sizeof(char));
                n = read(c.getClientSocket(), &input, sizeof(input));
            if (n == -1) {
                cout << "Error reading the message from the server";
                exit(-1);
            }
            cout << input << endl;
            } else
                cout << "No available rooms, press \"start\" to make new one" << endl;
            getline(cin,message);
            size = (int) message.size();
            command =  message.substr(0, message.find(" "));
        }

        if (command == "start"){
            n = read(c.getClientSocket(), &intRec, sizeof(intRec));
            if (n == -1) {
                cout << "Error reading the size of the message from the server";
                exit(-1);
            }
            if (intRec==1){
                LocalPlayer *b = new LocalPlayer(&l,&h,&c);
                RemotePlayer *w = new RemotePlayer(&l,&c);
                players.first=b;
                players.second=w;
                stopped = !stopped;
                cout<<"Waiting for the other player to connect...\n";
            }
            else if (intRec==-1){
                cout<<"This game is full, please chose other game or create new" << endl;
                command.clear();
            };
        }

        if (command == "join"){
            n = read(c.getClientSocket(), &intRec, sizeof(intRec));
            if (n == -1) {
                cout << "Error reading the size of the message from the server";
                exit(-1);
            }
            if (intRec==2){
                RemotePlayer *b =new RemotePlayer(&l,&c);
                LocalPlayer *w =new LocalPlayer(&l,&h,&c);
                players.first=b;
                players.second=w;
                stopped = !stopped;
            }
            else break;
        }

    }
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
//            try {
//                c.connectToServer();
//            } catch (const char *msg) {
//                cout << "Failed to connect to server. Reason:" << msg << endl;
//                exit(-1);
//            }
    sendToServer(players,l,board,c,h);


//            cout<<"Waiting for the other player to connect...\n";
//            int order;
//        //connect to server and gets 1 for black and 2 for white into order
//            int n = read(c.getClientSocket(), &order, sizeof(int));
//            if(n == -1) {
//                cout << "Error reading the turn of the player";
//                exit (-1);
//            }
//            if (order==1){

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
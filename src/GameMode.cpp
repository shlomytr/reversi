//
// Created by omer on 03/01/18.
//

#include <cstdlib>
#include <unistd.h>
#include <string.h>
#include "../include/GameMode.h"
#include "../include/AIPlayer.h"
#include "../include/LocalPlayer.h"
#include "../include/RemotePlayer.h"


using namespace std;

void GameMode::PrintMenu() {
    cout << "Please choose one of the following:\n'start <name>' to start a game with a name of 'name'\n"
            "'list_games' to get the current joinable games\n'join <name>' to join a game with a name of 'name'\n";
}

void GameMode::sendToServer (pair <Player *,Player *> &players, GameLogic &l, Board &board, Client &c, HumanPlayer &h) {


    string message;
    string command;
    int size;
    PrintMenu();
    cin.ignore();
    getline(cin, message);
    size = (int) message.size();
    command = message.substr(0, message.find(" "));

    bool stopped = false;
    do {

        while (command != "start" && command != "join" &&
               command != "list_games") {
            cout << "Invalid input. Please try again\n";

            getline(cin, message);
            size = (int) message.size();
            command = message.substr(0, message.find(" "));
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

        switch(commandTranslator(command)){
            //"start"
            case 1:
                cout << "Trying to connect to the room...\n";
                n = read(c.getClientSocket(), &intRec, sizeof(intRec));
                if (n == -1) {
                    cout << "Error reading the size of the message from the server";
                    exit(-1);
                }
                if (intRec == 1) {
                    LocalPlayer *b = new LocalPlayer(&l, &h, &c);
                    RemotePlayer *w = new RemotePlayer(&l, &c);
                    players.first = b;
                    players.second = w;
                    stopped = !stopped;
                } else if (intRec == -1) {
                    cout << "There is already a room with a name like this, please choose other name or join an available game" << endl;
                    command.clear();
                };
                break;

            //"join"
            case 2:
                n = read(c.getClientSocket(), &intRec, sizeof(intRec));
                if (n == -1) {
                    cout << "Error reading the size of the message from the server";
                    exit(-1);
                }
                if (intRec == 2) {
                    RemotePlayer *b = new RemotePlayer(&l, &c);
                    LocalPlayer *w = new LocalPlayer(&l, &h, &c);
                    players.first = b;
                    players.second = w;
                    stopped = !stopped;
                } else if (intRec == -1) {
                    cout << "The room is full, for available room please check our room_list" << endl;
                }else if (intRec == -2) {
                    cout << "The room doesnt exist, for available room please check our room_list" << endl;
                }
                break;

            //"list_games"
            case 3:
                n = read(c.getClientSocket(), &intRec, sizeof(intRec));
                if (n == -1) {
                    cout << "Error reading the size of the message from the server";
                    exit(-1);
                }
                if (intRec) {
                    char input[intRec];
                    bzero((char *)input, intRec*sizeof(char));
                    n = read(c.getClientSocket(), &input, sizeof(input));
                    if (n == -1) {
                        cout << "Error reading the message from the server";
                        exit(-1);
                    }
                    //prints the list of games
                    cout << "You can join the following rooms:" << endl << input << endl;
                    command =  "";
                } else
                    cout << "No available rooms, press \"start\" to make new one" << endl;
                break;

            default:
                break;
        }

        if(!stopped) {
        cout << endl;
        PrintMenu();
        getline(cin, message);
        size = (int) message.size();
        command = message.substr(0, message.find(" "));
        }

    } while (!stopped);
}

pair <Player *,Player *>  GameMode::chooseGameMode(GameLogic &l, Board &board, Printer &p, Client &c, HumanPlayer &h) {
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
        sendToServer(players,l,board,c,h);
    }
    return players;

}

int GameMode::commandTranslator(string command) {
    if(command == "start") {
        return 1;
    } else if(command == "join") {
        return 2;
    } else if(command == "list_games") {
        return 3;
    } else
        return 4;
}
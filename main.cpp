//
// Created by Shlomy and Omer
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "include/Board.h"
#include "include/Game.h"
#include "include/HumanPlayer.h"
#include "include/DeafultLogic.h"
#include "include/ConsolePrinter.h"
#include "include/Client.h"
#include "include/GameMode.h"


using namespace std;

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
    GameMode gameMode;
    pair <Player *, Player *> players = gameMode.chooseGameMode(logic,board, printer, client,*humanPlayer);
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
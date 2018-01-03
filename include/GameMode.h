//
// Created by omer on 03/01/18.
//

#ifndef REVERSI_GAMEMODE_H
#define REVERSI_GAMEMODE_H


#include "HumanPlayer.h"
#include "Client.h"

class GameMode {

public:

    void sendToServer (pair <Player *,Player *> &players, GameLogic &l, Board &board, Client &c, HumanPlayer &h);

    pair <Player *,Player *>  chooseGameMode(GameLogic &l, Board &board, Printer &p, Client &c, HumanPlayer &h);

    void PrintMenu();

    int commandTranslator(string command);
};


#endif //REVERSI_GAMEMODE_H

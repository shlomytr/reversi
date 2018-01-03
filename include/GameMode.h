//
// Created by omer on 03/01/18.
//

#ifndef REVERSI_GAMEMODE_H
#define REVERSI_GAMEMODE_H


#include "HumanPlayer.h"
#include "Client.h"

class GameMode {

public:

    /**
     * @name : sendToServer
     * @parameters : a pair of players , the game's Logic, Board, and an instance of HumanPlayer and Client
     * @return : the function is used if the player wish to play online and updates the player's pair accordingly
     *          furthermore, the function send and gets data from the server
     **/

    void sendToServer (pair <Player *,Player *> &players, GameLogic &l, Board &board, Client &c, HumanPlayer &h);

    /**
     * @name : chooseGameMode
     * @parameters : an instance of the game's Logic, Board, Printer, Client and HumanPlayer
     * @return : the function returns a pair of the player's wished game mode
     **/

    pair <Player *,Player *>  chooseGameMode(GameLogic &l, Board &board, Printer &p, Client &c, HumanPlayer &h);

    /**
     * @name : PrintMenu
     * @parameters : no parameters
     * @return : the function prints a message of welcome in the online play section
     **/

    void PrintMenu();

    /**
     * @name : commandTranslator
     * @parameters : a string of the command that wished to be used
     * @return : the function change the string to an known int and returns it
     **/

    int commandTranslator(string command);
};


#endif //REVERSI_GAMEMODE_H

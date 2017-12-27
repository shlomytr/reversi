//
// Created by shlomy on 07/12/17.
//

#ifndef REVERSI_LOCALPLAYER_H
#define REVERSI_LOCALPLAYER_H


#include "Client.h"
#include "HumanPlayer.h"

class LocalPlayer : public Player {

public:

    /**
     * @name : LocalPlayer
     * @parameters : an instance of GameLogic, HumanPlayer and Client
     * @return : the function creates a new instance of LocalPlayer
     **/

    LocalPlayer(GameLogic *l, HumanPlayer *player, Client *client);

    /**
     * @name : playOneTurn
     * @parameters : true if it is the black's player turn, false otherwise
     * @return : the function use HumanPlayer's playOneMove function and then send it
     **/

    virtual void playOneTurn(bool blacksTurn);

    /**
    * @name : DeclareNoMoves
    * @parameters : no parameters
    * @return : the function notify that the player can't play, and then send it to the server
    **/

    virtual void declareNoMoves();

    /**
     * @name : onlineEnd
     * @parameters : no parameters
     * @return : the function send a message to the server declaring that the current game has ended
     **/

    virtual void onlineEnd();


protected:
    HumanPlayer *player;
    Client *client;
    string intToString (int a);

    void sendToServer(string message);

};


#endif //REVERSI_LOCALPLAYER_H

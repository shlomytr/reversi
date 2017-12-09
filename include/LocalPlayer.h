//
// Created by shlomy on 07/12/17.
//

#ifndef REVERSI_LOCALPLAYER_H
#define REVERSI_LOCALPLAYER_H


#include "Client.h"
#include "HumanPlayer.h"

class LocalPlayer : public Player {

public:


    LocalPlayer(GameLogic *l, HumanPlayer *player, Client *client);

    virtual void playOneTurn(bool blacksTurn);

    /**
    * @name : DeclareNoMoves
    * @parameters : no parameters
    * @return : the function notify that the player can't play
    **/

    virtual void declareNoMoves();

    virtual void onlineEnd();


protected:
    HumanPlayer *player;
    Client *client;
    string intToString (int a);

};


#endif //REVERSI_LOCALPLAYER_H

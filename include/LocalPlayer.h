//
// Created by shlomy on 07/12/17.
//

#ifndef REVERSI_LOCALPLAYER_H
#define REVERSI_LOCALPLAYER_H


#include "Client.h"
#include "HumanPlayer.h"

class LocalPlayer : Client {

public:
    LocalPlayer(GameLogic *l, const char *serverIP, int serverPort, HumanPlayer *player);

    virtual void playOneTurn(bool blacksTurn);

    /**
    * @name : DeclareNoMoves
    * @parameters : no parameters
    * @return : the function notify that the player can't play
    **/

    virtual void declareNoMoves();

protected:
    HumanPlayer *player;


};


#endif //REVERSI_LOCALPLAYER_H

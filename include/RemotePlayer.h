//
// Created by shlomy on 07/12/17.
//

#ifndef REVERSI_REMOTEPLAYER_H
#define REVERSI_REMOTEPLAYER_H


#include "Client.h"

class RemotePlayer : Client {
public:
    RemotePlayer(GameLogic *l, const char *serverIP, int serverPort);

    virtual void playOneTurn(bool blacksTurn);

    /**
    * @name : DeclareNoMoves
    * @parameters : no parameters
    * @return : the function notify that the player can't play
    **/

    virtual void declareNoMoves();
};


#endif //REVERSI_REMOTEPLAYER_H

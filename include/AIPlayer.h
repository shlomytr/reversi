//
// Created by shlomy on 29/11/17.
//

#ifndef REVERSI_AIPLAYER_H
#define REVERSI_AIPLAYER_H


#include "Player.h"

class AIPlayer : public Player {
protected:
    Board *board;
public:
    AIPlayer(GameLogic *l, Board *board);

    virtual void playOneTurn(bool myTurn);

};


#endif //REVERSI_AIPLAYER_H

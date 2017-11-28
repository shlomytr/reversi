//
// Created by Shlomy Trajber
// ID - 305626962
//

#ifndef EX1_HUMANPLAYER_H
#define EX1_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer : public Player {
public:

    /**
    * @name : HumanPlayer
    * @parameters : no parameters
    * @return : the function creates a new instance of HumanPlayer
    **/

    HumanPlayer(GameLogic *gameLogic);

    virtual void playOneTurn(bool myTurn);
};


#endif //EX1_HUMANPLAYER_H

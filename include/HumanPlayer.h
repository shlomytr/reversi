//
// Created by Shlomy and Omer
//

#ifndef EX1_HUMANPLAYER_H
#define EX1_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer : public Player {
public:

    /**
    * @name : HumanPlayer
    * @parameters : an instance of GameLogic
    * @return : the function creates a new instance of HumanPlayer
    **/

    HumanPlayer(GameLogic *gameLogic);

    /**
     * @name : playOneTurn
     * @parameters : true if it is the black's player turn, false otherwise
     * @return : the function gets an input from the user and makes a move accordingly
     **/

    virtual void playOneTurn(bool blacksTurn);
};


#endif //EX1_HUMANPLAYER_H

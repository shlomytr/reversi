//
// Created by Shlomy and Omer
//

#ifndef EX1_HUMANPLAYER_H
#define EX1_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer : public Player {
protected:
    Printer *printer;
public:

    /**
    * @name : HumanPlayer
    * @parameters : instances of GameLogic and Printer
    * @return : the function creates a new instance of HumanPlayer
    **/

    HumanPlayer(GameLogic *gameLogic, Printer *printer);

    /**
     * @name : playOneTurn
     * @parameters : true if it is the black's player turn, false otherwise
     * @return : the function gets an input from the user and makes a move accordingly
     **/

    virtual void playOneTurn(bool blacksTurn);

    /**
     * @name : onlineEnd
     * @parameters : no parameters
     * @return : the function does not do anything
     **/

    virtual void onlineEnd();

};


#endif //EX1_HUMANPLAYER_H

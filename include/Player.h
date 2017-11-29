//
// Created by Shlomy and Omer
//

#ifndef EX1_PLAYER_H
#define EX1_PLAYER_H


#include "GameLogic.h"

class Player {
protected:
    GameLogic *logic;
    bool canPlay;
    int type;
    pair<int, int> lastMove;

public:

    /**
    * @name : Player
    * @parameters : no parameters
    * @return : the function creates a new instance of player
    **/

    Player(GameLogic *l);

    /**
    * @name : getCanPlay
    * @parameters : no parameters
    * @return : the function returns true if the player has a possible move to play or false otherwise
    **/

    bool getCanPlay();

    /**
    * @name : setCanPlay
    * @parameters : true or false
    * @return : the function sets whether the player has a possible move or not
    **/

    void setCanPlay(bool b);

    /**
    * @name : getLastMove
    * @parameters : no parameters
    * @return : the function returns a pair with the index of the last move played
    **/

    pair<int, int> getLastMove();

    /**
    * @name : getType
    * @parameters : no parameters
    * @return : the function returns the type of the player (HumanPlayer, AIPlayer etc)
    **/

    int getType();

    /**
    * @name : playOneTurn
    * @parameters : true if it's the black's player turn, false otherwise
    * @return : the function makes a move in the game
    **/

    virtual void playOneTurn(bool blacksTurn) = 0;

};


#endif //EX1_PLAYER_H

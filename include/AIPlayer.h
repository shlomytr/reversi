//
// Created by Shlomy and Omer
//

#ifndef REVERSI_AIPLAYER_H
#define REVERSI_AIPLAYER_H


#include "Player.h"

class AIPlayer : public Player {
protected:
    Board *board;
public:

    /**
     * @name : AIPlayer
     * @parameters : instances of GameLogic and Board
     * @return : the function creates an instance of AIPlayer
     **/

    AIPlayer(GameLogic *l, Board *board);

    /**
     * @name : playOneTurn
     * @parameters : true if it is the black's player turn, false otherwise
     * @return : the function uses the minimax algorithem to play the next move of the computer
     **/

    virtual void playOneTurn(bool blacksTurn);

};


#endif //REVERSI_AIPLAYER_H

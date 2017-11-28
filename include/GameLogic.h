//
// Created by Shlomy Trajber
// ID - 305626962
//

#ifndef EX1_GAMELOGIC_H
#define EX1_GAMELOGIC_H


#include "Board.h"

class GameLogic {
public:

    /**
     * @name : GameLogic
     * @parameters : an instance of board
     * @return : the function create an instance of GameLogic
     **/

    GameLogic(Board *board);

    /**
     * @name : possibleMoves
     * @parameters : true if it's the black's player turn, false otherwise
     * @return : if there are possible moves, the function prints them, puts them in the posArray
     *           and returns true, otherwise returns false
     **/

    virtual bool possibleMoves(bool blacksTurn) = 0;

    /**
     * @name : move
     * @parameters : true if it's the black's player turn, false otherwise, and the index for the next move
     * @return : the function makes the move that the user put in
     **/

    void move(bool blacksTurn, int i, int j);

protected:
    Board *board;

    /**
     * @name : checkAdTile
     * @parameters : the turn, the index that the function will check. the way to move and a boolean
     *               expression that is true when we find a candidate that is suitable
     * @return : the function uses recursion to find whether we can put a tile in the current index or not
     **/

    virtual bool checkAdTile(bool blacksTurn, int i, int j, int rowDif, int colDif, bool foundACandidate) = 0;

    /**
     * @name : changeBoard
     * @parameters : the turn, the index of the input of the user, the way to move and a boolean
     *               expression that is true when we find a candidate that is suitable
     * @return : the function uses recursion to change all the tiles that according to the rules and change
     *           the score accordingly
     **/

    virtual bool changeBoard(bool blacksTurn, int i, int j, int rowDif, int colDif, bool foundACandidate) = 0;

    /**
     * @name : changeSingleTile
     * @parameters : the turn and the index that is need to be changed
     * @return : changes the tile, adds to the score of player and doesn't decrease the score of the opponent
     **/

    void changeSingleTile(bool blacksTurn, int i, int j);

    /**
     * @name : flipTile
     * @parameters : the turn and the index that is need to be changed
     * @return : changes the tile, adds to the score of player and decreases the score of the opponent
     **/

    void flipTile(bool blacksTurn, int i, int j);

public:
    bool getPosCell(int i, int j);

};


#endif //EX1_GAMELOGIC_H

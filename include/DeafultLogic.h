//
// Created by Shlomy and Omer
//

#ifndef EX1_DEAFULTLOGIC_H
#define EX1_DEAFULTLOGIC_H


#include "GameLogic.h"

class DefaultLogic : public GameLogic {
public:

    /**
     * @name : DefaultLogic
     * @parameters : an instance of board
     * @return : the function create an instance of DefaultLogic
     **/

    DefaultLogic(Board *board);


    /**
     * @name : possibleMoves
     * @parameters : true if it's the black's player turn, false otherwise
     * @return : if there are possible moves, the function prints them, puts them in the posArray
     *           and returns true, otherwise returns false
     **/

    virtual bool possibleMoves(bool blacksTurn, int type);

    /**
     * @name : getType
     * @parameters : no parameters
     * @return : the function returns the string "DeafultLogic"
     **/

    virtual string getType();


protected:

    /**
     * @name : checkAdTile
     * @parameters : the turn, the index that the function will check. the way to move and a boolean
     *               expression that is true when we find a candidate that is suitable
     * @return : the function uses recursion to find whether we can put a tile in the current index or not
     **/

    virtual bool checkAdTile(bool blacksTurn, int i, int j, int rowDif, int colDif, bool foundACandidate);

    /**
     * @name : changeBoard
     * @parameters : the turn, the index of the input of the user, the way to move and a boolean
     *               expression that is true when we find a candidate that is suitable
     * @return : the function uses recursion to change all the tiles that according to the rules and change
     *           the score accordingly
     **/

    virtual bool changeBoard(bool blacksTurn, int i, int j, int rowDif, int colDif, bool foundACandidate);

};


#endif //EX1_DEAFULTLOGIC_H

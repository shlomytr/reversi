//
// Created by shlomy on 05/12/17.
//

#ifndef REVERSI_PRINTER_H
#define REVERSI_PRINTER_H


#include "Board.h"

class Printer {
public:


    /**
     * @name : printNextTurn
     * @parameters : no parameters
     * @return : the function prints a message declaring who has the next turn
     **/

    virtual void printNextTurn(bool blacksTurn) = 0;

    /**
     * @name : printNoMoves
     * @parameters : true if it is the black's player turn, false otherwise
     * @return : the function prints a message declaring that the player doesn't have possible moves
     **/

    virtual void printNoMoves() = 0;

    /**
     * @name : printLastMove
     * @parameters : the turn and the index of the last move that was played
     * @return : the function prints a message declaring what was the last move that was played
     **/

    virtual void printLastMove(bool blacksTurn, int i, int j) = 0;

    /**
     * @name : printBoard
     * @parameters : the board that the game is played in
     * @return : the function prints the board
     **/

    virtual void printBoard(Board &b) = 0;

    /**
     * @name : printsWhoWon
     * @parameters : the board that the game is played in
     * @return : the function prints the final board, score and who's won
     **/

    virtual void printsWhoWon(Board &b) = 0;

    /**
     * @name : printEnterNextTurn
     * @parameters : no parameters
     * @return : the function prints a message telling the user to enter a next turn
     **/

    virtual void printEnterNextTurn() = 0;

    /**
     * @name : PrintInvalidMove
     * @parameters : no parameters
     * @return : the function prints a message telling the user that he entered an invalid move
     **/

    virtual void PrintInvalidMove() = 0;

    /**
     * @name : printPosMoves
     * @parameters : the board that the game is played in
     * @return : the function prints the possible choices to pu a tile in
     **/

    virtual void printPosMoves (Board &b) = 0;



};


#endif //REVERSI_PRINTER_H

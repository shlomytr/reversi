//
// Created by shlomy on 05/12/17.
//

#ifndef REVERSI_CONSOLEPRINTER_H
#define REVERSI_CONSOLEPRINTER_H


#include "Printer.h"

class ConsolePrinter : public Printer {

public:

    /**
     * @name : printNextTurn
     * @parameters : no parameters
     * @return : the function prints a message declaring who has the next turn
     **/

    virtual void printNextTurn(bool blacksTurn);

    /**
     * @name : printNoMoves
     * @parameters : true if it is the black's player turn, false otherwise
     * @return : the function prints a message declaring that the player doesn't have possible moves
     **/

    virtual void printNoMoves();

    /**
     * @name : printLastMove
     * @parameters : the turn and the index of the last move that was played
     * @return : the function prints a message declaring what was the last move that was played
     **/

    virtual void printLastMove(bool blacksTurn, int i, int j);

    /**
     * @name : printBoard
     * @parameters : the board that the game is played in, and a boolean that
     * is true if it is the last print or false otherwise
     * @return : the function prints the board
     **/

    virtual void printBoard(Board &b, bool onlyPrintBoard);

    /**
     * @name : printsWhoWon
     * @parameters : the board that the game is played in
     * @return : the function prints the final score and who won
     **/

    virtual void printsWhoWon(Board &b);

    /**
     * @name : printEnterNextTurn
     * @parameters : no parameters
     * @return : the function prints a message telling the user to enter a next turn
     **/

    virtual void printEnterNextTurn();

    /**
     * @name : PrintInvalidMove
     * @parameters : no parameters
     * @return : the function prints a message telling the user that he entered an invalid move
     **/

    virtual void PrintInvalidMove();

    /**
     * @name : printPosMoves
     * @parameters : the board that the game is played in
     * @return : the function prints the possible choices to pu a tile in
     **/

    virtual void printPosMoves (Board &b);
};


#endif //REVERSI_CONSOLEPRINTER_H

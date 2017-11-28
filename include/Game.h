//
// Created by Shlomy Trajber
// ID - 305626962
//

#ifndef EX1_GAME_H
#define EX1_GAME_H


#include "Player.h"
#include "Board.h"
#include "GameLogic.h"

class Game {

public:
    void playGame();

    /**
     * @name : Game
     * @parameters : instances of the board, the players, and the game logic
     * @return : the function creates new instance of Game
     **/

    Game(Board *board, Player *black, Player *white, GameLogic *logic);

private:
    Player *black;
    Player *white;
    Board *board;
    GameLogic *logic;
    bool blacksTurn = true;

    /**
     * @name : printNextTurn
     * @parameters : no parameters
     * @return : the function prints a message declaring who has the next turn
     **/

    void printNextTurn();

    /**
     * @name : printNoMoves
     * @parameters : no parameters
     * @return : the function prints a message declaring that the player doesn't have possible moves
     **/

    void printNoMoves();

    /**
     * @name : printLastMove
     * @parameters : the index of the last move that was played
     * @return : the function prints a message declaring what was the last move that was played
     **/

    void printLastMove(int i, int j);

    /**
     * @name : printBoard
     * @parameters : no parameters
     * @return : the function prints the board
     **/

    void printBoard();

    /**
     * @name : isGameNotOver
     * @parameters : no parameters
     * @return : the function returns true if the game is over or not
     **/

    bool isGameNotOver();

    /**
     * @name : isGameNotOver
     * @parameters : no parameters
     * @return : the function prints the final score and who won
     **/

    void printsWhoWon();

    /**
     * @name : enterNextMove
     * @parameters : no parameters
     * @return : the function asks for the user for input of the next move, and when it is legal returns it
     **/

    pair<int, int> enterNextMove();

    int chooseGameMode();

};


#endif //EX1_GAME_H
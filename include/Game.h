//
// Created by Shlomy and Omer
//

#ifndef EX1_GAME_H
#define EX1_GAME_H


#include "Player.h"
#include "Board.h"
#include "GameLogic.h"
#include "Printer.h"

class Game {

public:

    /**
     * @name : Game
     * @parameters : instances of the board, the players, and the game's logic
     * @return : the function creates new instance of Game
     **/

    Game(Board *board, Player *black, Player *white, GameLogic *logic, Printer *printer);

    /**
     * @name : playGame
     * @parameters : no parameters
     * @return : the function runs the game
     **/

    void playGame();



private:
    Player *black;
    Player *white;
    Board *board;
    GameLogic *logic;
    Printer *printer;
    bool blacksTurn;

    /**
     * @name : printNextTurn
     * @parameters : no parameters
     * @return : the function prints a message declaring who has the next turn
     **/


    /**
     * @name : isGameNotOver
     * @parameters : no parameters
     * @return : the function returns true if the game is over or not
     **/

    bool isGameNotOver();




};


#endif //EX1_GAME_H
//
// Created by Shlomy Trajber
// ID - 305626962
//

#ifndef EX1_PLAYER_H
#define EX1_PLAYER_H


class Player {
protected:
    bool canPlay;
    int type;
public:

    /**
    * @name : Player
    * @parameters : no parameters
    * @return : the function creates a new instance of player
    **/

    Player();

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
};


#endif //EX1_PLAYER_H

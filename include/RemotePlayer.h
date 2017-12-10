//
// Created by shlomy on 07/12/17.
//

#ifndef REVERSI_REMOTEPLAYER_H
#define REVERSI_REMOTEPLAYER_H


#include "Client.h"

class RemotePlayer : public Player {
public:

    /**
     * @name : RemotePlayer
     * @parameters : an instance of GameLogic and Client
     * @return : the function creates a new instance of RemotePlayer
     **/

    RemotePlayer( GameLogic *l, Client *client);

    /**
     * @name : playOneTurn
     * @parameters : true if it is the black's player turn, false otherwise
     * @return : the function reads from the server the rival's move and then do it in the board
     **/

    virtual void playOneTurn(bool blacksTurn);

    /**
     * @name : onlineEnd
     * @parameters : no parameters
     * @return : the function does not do anything
     **/

    virtual void onlineEnd();

protected:
    Client *client;
};




#endif //REVERSI_REMOTEPLAYER_H

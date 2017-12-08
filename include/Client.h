//
// Created by shlomy on 06/12/17.
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H


#include "Player.h"

class Client : public Player {
public:
    Client(GameLogic *l, const char *serverIP, int serverPort);
    void connectToServer();
    int sendExercise(int arg1, char op, int arg2);
    virtual void playOneTurn(bool blacksTurn) = 0;

protected:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};



#endif //REVERSI_ONLINEPLAYER_H

//
// Created by shlomy on 06/12/17.
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H


#include "Player.h"

class Client  {
public:
    Client(const char *serverIP, int serverPort);
    void connectToServer();
    int getClientSocket();

protected:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};



#endif //REVERSI_ONLINEPLAYER_H

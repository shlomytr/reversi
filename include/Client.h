//
// Created by shlomy on 06/12/17.
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H


#include "Player.h"

class Client  {
public:

    /**
     * @name : Client
     * @parameters : the ip of the server and the number of the port
     * @return : the function creates a new instance of Client
     **/

    Client(const char *serverIP, int serverPort);

    /**
     * @name : connectToServer
     * @parameters : no parameters
     * @return : the function connects the client to the server
     **/

    void connectToServer();

    /**
     * @name : getClientSocket
     * @parameters : no parameters
     * @return : the function returns the number of the socket
     **/

    int getClientSocket();

protected:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};



#endif //REVERSI_ONLINEPLAYER_H

//
// Created by shlomy on 07/12/17.
//

#include <unistd.h>
#include "../include/RemotePlayer.h"


RemotePlayer::RemotePlayer( GameLogic *l, Client *client) : Player(l) {
    this->client = client;
    this->type = 4;
}

void RemotePlayer::playOneTurn(bool blacksTurn) {
    static const int maxMove = 8;
    char input[maxMove];
    cout<<"Waiting fot the other player's move...\n";
    int n = read(client->getClientSocket(), &input, sizeof(input));
    //need to understand how to get the move for the server, cast it to int and then insert it in the board
    cout<<input;

}

void RemotePlayer::onlineEnd() {}




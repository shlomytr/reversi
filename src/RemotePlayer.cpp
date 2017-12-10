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
    int row;
    int col;
    cout<<"Waiting fot the other player's move...\n";
    int r = read(client->getClientSocket(), &row, sizeof(row));
    int c = read(client->getClientSocket(), &col, sizeof(col));
    //need to understand how to get the move for the server, cast it to int and then insert it in the board
    cout<< row << ", " << col << endl;
    lastMove.first = row;
    lastMove.second = col;
    logic->move(blacksTurn, row, col);
}

void RemotePlayer::onlineEnd() {}




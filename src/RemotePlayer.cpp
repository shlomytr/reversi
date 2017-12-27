//
// Created by shlomy on 07/12/17.
//

#include <unistd.h>
#include <cstdlib>
#include "../include/RemotePlayer.h"


RemotePlayer::RemotePlayer( GameLogic *l, Client *client) : Player(l) {
    this->client = client;
    this->type = 4;
}

void RemotePlayer::playOneTurn(bool blacksTurn) {
    int row, col;
    int size = 0;
    cout<<"Waiting fot the other player's move...\n";
    int r = read(client->getClientSocket(), &size, sizeof(int));
    if (r == -1) {
        throw "Error reading the size of the move";
    }
    char input[size];
    r = read(client->getClientSocket(), &input, size * sizeof(char));
    if (r == -1) {
        throw "Error reading the size of the move";
    }
    row = atoi(reinterpret_cast<const char *>(input[0]));
    col = atoi(reinterpret_cast<const char *>(input[2]));    cout<< row << ", " << col << endl;
    lastMove.first = row;
    lastMove.second = col;
    logic->move(blacksTurn, row, col);
}

void RemotePlayer::onlineEnd() {}




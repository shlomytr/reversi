//
// Created by shlomy on 07/12/17.
//

#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include "../include/LocalPlayer.h"

LocalPlayer::LocalPlayer( GameLogic *l, HumanPlayer *player, Client *client) : Player(l) {
    this->client = client;
    this->player = player;
    this->type = 3;
}



void LocalPlayer::playOneTurn(bool blacksTurn) {
    player->playOneTurn(blacksTurn);
    lastMove.first = player->getLastMove().first;
    lastMove.second = player->getLastMove().second;
    int n = write(client->getClientSocket(), &lastMove.first, sizeof(lastMove.first));
    if (n == -1) {
        throw "Error writing Move to socket";
    }
    n = write(client->getClientSocket(), &lastMove.second, sizeof(lastMove.first));
    if (n == -1) {
        throw "Error writing Move to socket";
    }

}

void LocalPlayer::declareNoMoves() {
    player->declareNoMoves();
    string message = "NoMove";
    int n = write(client->getClientSocket(), &message, sizeof(message));
    if (n == -1) {
        throw "Error writing 'NoMove' to socket";
    }
}

string LocalPlayer::intToString(int a) {
    ostringstream temp;
    temp<<a;
    return temp.str();
}

void LocalPlayer::onlineEnd() {
    string message = "End";
    int n = write(client->getClientSocket(), &message, sizeof(message));
    if (n == -1)
        throw "Error writing 'End' to socket";
}



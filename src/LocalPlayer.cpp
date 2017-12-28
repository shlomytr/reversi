//
// Created by shlomy on 07/12/17.
//

#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <cstring>
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
    string move = intToString(lastMove.first);
    move.append(" ");
    move.append(intToString(lastMove.second));
    sendToServer(move);
}

void LocalPlayer::declareNoMoves() {
    player->declareNoMoves();
    this->canPlay=false;
    sendToServer("NoMove");
}

string LocalPlayer::intToString(int a) {
    ostringstream temp;
    temp<<a;
    return temp.str();
}

void LocalPlayer::onlineEnd() {
    sendToServer("End");
}

void LocalPlayer::sendToServer(string m) {
    int size= (int) m.size();
    char message[size];
    strcpy(message,m.c_str());
    int n = write(client->getClientSocket(), &size, sizeof(size));
    if (n == -1) {
        throw "Error writing size to socket";
    }
    n = write(client->getClientSocket(), &message, sizeof(message));
    if (n == -1) {
        throw "Error writing Move to socket";
    }

}





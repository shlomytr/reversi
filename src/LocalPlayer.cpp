//
// Created by shlomy on 07/12/17.
//

#include <unistd.h>
#include "../include/LocalPlayer.h"

LocalPlayer::LocalPlayer(GameLogic *l, const char *serverIP, int serverPort, HumanPlayer *player) : Client(l, serverIP, serverPort) {
    this->player=player;
}


void LocalPlayer::playOneTurn(bool blacksTurn) {
    player->playOneTurn(blacksTurn);
    pair <int,int> lastMove = player->getLastMove();
    int n = write(clientSocket, &lastMove, sizeof(lastMove));
    if (n == -1) {
        throw "Error writing lastMove to socket";
    }

}

void LocalPlayer::declareNoMoves() {
    Player::declareNoMoves();

}



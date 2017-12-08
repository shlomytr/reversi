//
// Created by shlomy on 07/12/17.
//

#include "../include/RemotePlayer.h"

RemotePlayer::RemotePlayer(GameLogic *l, const char *serverIP, int serverPort) : Client(l, serverIP, serverPort) {}

void RemotePlayer::playOneTurn(bool blacksTurn) {

}

void RemotePlayer::declareNoMoves() {
    Player::declareNoMoves();
}

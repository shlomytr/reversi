//
// Created by Shlomy and Omer
//

#include "../include/Player.h"

Player::Player(GameLogic *l):logic(l){
    canPlay = true;
}

bool Player::getCanPlay() {
    return canPlay;
}

void Player::declareNoMoves() {
    canPlay = false;
}

pair<int ,int > Player::getLastMove() {
    return lastMove;
}

int Player::getType() {
    return this->type;
}
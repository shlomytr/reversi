//
// Created by Shlomy Trajber
// ID - 305626962
//

#include "../include/Player.h"

Player::Player(GameLogic *l):logic(l){
    canPlay = true;
}

bool Player::getCanPlay() {
    return canPlay;
}

void Player::setCanPlay(bool b) {
    canPlay = b;

}

pair<int ,int > Player::getLastMove() {
    return lastMove;
}

int Player::getType() {
    return this->type;
}
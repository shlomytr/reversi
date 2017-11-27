//
// Created by Shlomy Trajber
// ID - 305626962
//

#include "Player.h"

Player::Player() {
    canPlay = true;
}

bool Player::getCanPlay() {
    return canPlay;
}

void Player::setCanPlay(bool b) {
    canPlay = b;

}

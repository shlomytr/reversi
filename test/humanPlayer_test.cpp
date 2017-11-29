//
// Created by omer on 28/11/17.
//

#include <gtest/gtest.h>
#include "../include/DeafultLogic.h"
#include "../include/HumanPlayer.h"

TEST(humanPlayerTest, sanityCheak) {
    Board board;
    DefaultLogic logic = DefaultLogic(&board);
    HumanPlayer player = HumanPlayer(&logic);
    player.setCanPlay(true);
    ASSERT_TRUE(player.getCanPlay());
//    player.playOneTurn()
//    player.getLastMove();
}
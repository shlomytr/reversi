//
// Created by omer on 28/11/17.
//

#include <gtest/gtest.h>
#include "../include/DeafultLogic.h"
#include "../include/HumanPlayer.h"
#include "../include/AIPlayer.h"

TEST(humanPlayerTest, sanityCheak) {
    Board board;
    DefaultLogic logic = DefaultLogic(&board);
    HumanPlayer player = HumanPlayer(&logic);
    player.setCanPlay(true);
    ASSERT_TRUE(player.getCanPlay());
    ASSERT_EQ(player.getType(),1);

}

TEST(AIPlayerTest, sanityCheak) {
    Board board;
    DefaultLogic logic = DefaultLogic(&board);
    AIPlayer player = AIPlayer(&logic, &board);
    player.setCanPlay(true);
    ASSERT_TRUE(player.getCanPlay());
    ASSERT_EQ(player.getType(),2);
}
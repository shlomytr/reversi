//
// Created by omer on 28/11/17.
//

#include <gtest/gtest.h>
#include "../include/DeafultLogic.h"
#include "../include/HumanPlayer.h"
#include "../include/AIPlayer.h"
#include "../include/ConsolePrinter.h"

TEST(humanPlayerTest, sanityCheak) {
    Board board(8);
    ConsolePrinter printer;
    DefaultLogic logic = DefaultLogic(&board);
    HumanPlayer player = HumanPlayer(&logic, &printer);
    ASSERT_TRUE(player.getCanPlay());
    ASSERT_EQ(player.getType(),1);

}

TEST(AIPlayerTest, sanityCheak) {
    Board board(8);
    DefaultLogic logic = DefaultLogic(&board);
    AIPlayer player = AIPlayer(&logic, &board);
    ASSERT_TRUE(player.getCanPlay());
    ASSERT_EQ(player.getType(),2);
}
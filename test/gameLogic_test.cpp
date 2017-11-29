//
// Created by omer on 28/11/17.
//

#include <gtest/gtest.h>
#include "../include/GameLogic.h"
#include "../include/DeafultLogic.h"

TEST(defaultLogicTest, sanityCheak) {
    Board board;
    DefaultLogic logic = DefaultLogic(&board);
    ASSERT_EQ(logic.getType(), "DefaultLogic");
    board.setPosCell(3,3,true);
    EXPECT_TRUE(logic.getPosCell(3,3));
    ASSERT_TRUE(logic.possibleMoves(true,1));
}
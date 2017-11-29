//
// Created by omer on 28/11/17.
//

#include <gtest/gtest.h>
#include "../include/Game.h"


TEST(BoardTest, initializationCheak) {
    Board board;
    EXPECT_EQ(board.getBTiles(),2);
    EXPECT_EQ(board.getWTiles(),2);
    EXPECT_EQ(board.getCell(3,3),'o');
    EXPECT_EQ(board.getCell(3,4),'x');
    EXPECT_EQ(board.getCell(3,5),' ');
    ASSERT_FALSE(board.isFull());

}

TEST(BoardTest, boardAdgasments) {
    Board board;
    board.setPosCell(3,3,true);
    board.setCell(1,1,'x');
    board.addToBTiles(1);
    ASSERT_TRUE(board.getPosCell(3,3));
    ASSERT_EQ(board.getCell(1,1),'x');
    EXPECT_EQ(board.getBTiles(),3);
}
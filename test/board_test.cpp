//
// Created by omer on 28/11/17.
//

#include <gtest/gtest.h>
#include "../include/Game.h"


TEST(BoardTest, initializationCheak) {
    Board board(8);
    EXPECT_EQ(board.getBTiles(),2);
    EXPECT_EQ(board.getWTiles(),2);
    EXPECT_EQ(board.getCell(3,3),'o');
    EXPECT_EQ(board.getCell(3,4),'x');
    EXPECT_EQ(board.getCell(3,5),' ');
    ASSERT_FALSE(board.isFull());

}

TEST(BoardTest, boardAdgasments) {
    Board board(8);
    board.setPosCell(3,3,true);
    board.setCell(1,1,board.black);
    board.addToBTiles(1);
    ASSERT_TRUE(board.getPosCell(3,3));
    ASSERT_EQ(board.getCell(1,1),'x');
    EXPECT_EQ(board.getBTiles(),3);
    for (int i = 0; i < board.getBoardSize(); i++)
        for (int j = 0; j < board.getBoardSize(); j++)
            board.setCell(i,j,board.black);
    ASSERT_TRUE(board.isFull());
}
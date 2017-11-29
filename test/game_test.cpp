//
// Created by omer on 28/11/17.
//

#include <gtest/gtest.h>
#include "../include/Game.h"


TEST(GameTest, sanityCheak) {
    Game game();
    EXPECT_EQ(2,2);
}
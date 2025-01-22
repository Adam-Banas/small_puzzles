#include <gtest/gtest.h>

#include "../solution/solution.hpp"

// Just a basic test to serve as a base for puzzles
TEST(SolutionTest, BasicTest) {
    int a = 7;
    int b = -3;

    EXPECT_EQ(a + b, add(a, b));
}
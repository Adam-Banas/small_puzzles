#include <gtest/gtest.h>

#include "../solution/solution.hpp"

using SolutionTest = ::testing::TestWithParam<std::tuple<std::string, std::string, int>>;

TEST_P(SolutionTest, Simple) {
    auto a = std::get<0>(GetParam());
    auto b = std::get<1>(GetParam());
    auto expected_length = std::get<2>(GetParam());

    EXPECT_EQ(expected_length, lcs(a, b));
}

INSTANTIATE_TEST_SUITE_P(
    SolutionTest, SolutionTest,
    ::testing::Values(
        std::make_tuple("ABCDA", "ACBDA", 4), std::make_tuple("ABBB", "BBBA", 3),
        std::make_tuple("ABCDE", "ABC", 3),
        std::make_tuple("ABCaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaDEFG",
                        "ABCbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbDEFG", 7)));
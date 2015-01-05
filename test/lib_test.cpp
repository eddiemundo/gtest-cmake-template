#include <gtest/gtest.h>
#include <lib.h>
TEST(SquareRootTest, PositiveNos) {
	EXPECT_EQ(18.0, squareRoot(324.0));
	EXPECT_EQ(25.4, squareRoot(645.16));
	EXPECT_EQ(50.3321, squareRoot(2533.310224));
}

TEST(SquareRootTest, ZeroAndNegativeNos) {
	ASSERT_EQ(0.0, squareRoot(0.0));
	ASSERT_EQ(-1, squareRoot(-22.0));
}
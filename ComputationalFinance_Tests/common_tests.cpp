#include "stdafx.h""
#include "common.h"

namespace ComputationalFinance_Tests_Common
{
    TEST(SquareTests, Square)
    {
        EXPECT_EQ(0, square(0));
        EXPECT_EQ(4, square(-2));
    }
}

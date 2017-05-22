#include "stdafx.h""
#include "common.h"
#include <gmock/gmock-matchers.h>

using namespace testing;

using namespace Common;

namespace CommonTests
{
    TEST(SquareTests, Square)
    {
        EXPECT_EQ(0, square(0));
        EXPECT_EQ(4, square(-2));
    }

    TEST(RoundVectorDigits, round_digits)
    {
        vector<double> 
            input = { 10.212312412, 4.53242342, 3.44324234, 5.6664 },
            expected = { 10.2, 4.5, 3.4, 5.7 };

        auto actual = round_digits( input, 1 );

        EXPECT_THAT( expected, ContainerEq( actual ) );
    }
}

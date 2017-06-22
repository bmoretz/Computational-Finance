#include "stdafx.h"

#include "CalculationTemplate.h"
#include <gmock/gmock-matchers.h>

using namespace Common;

using namespace testing;

namespace CommonTests
{
    class ComputationTemplateTests :
            public Test
    {
    protected:

        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F(ComputationTemplateTests, BasicFactoralTest_1)
    {
        auto expected = 120;

        auto actual = Factorial<5>::result;

        EXPECT_EQ( expected, actual );
    }

    TEST_F(ComputationTemplateTests, BasicFactoralTest_2)
    {
        auto expected = 720;

        auto actual = Factorial<6>::result;

        EXPECT_EQ( expected, actual );
    }

    TEST_F(ComputationTemplateTests, ChoiceNumberTest_1)
    {
        auto expected = 210;

        auto actual = ChoiceNumber<10,4>::result;

        EXPECT_EQ( expected, actual );
    }
}
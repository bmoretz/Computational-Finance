#include "stdafx.h"

#include "common.h"
#include "Date.h"
#include <gmock/gmock-matchers.h>
#include "FileError.h"

using namespace std;
using namespace Common;

using namespace testing;

namespace CommonTests
{
    class DateTests :
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

    TEST_F(DateTests, BookTest)
    {
        auto expectedDayOfWeek = "Saturday";
        auto expectedInterval = 27;

        Date firstDate( 2015, 1, 3 );
        auto dayOfWeek = firstDate.getDayOfWeek();

        auto actualDayOfWeek = firstDate.toStringDate( dayOfWeek );

        EXPECT_EQ( expectedDayOfWeek, actualDayOfWeek );

        Date secondDate( 2014, 12, 5 );

        EXPECT_LT( secondDate, firstDate );

        ++secondDate;
        ++secondDate;

        auto actualInterval = firstDate.daysInterval( secondDate );

        EXPECT_EQ( expectedInterval, actualInterval );
    }
}

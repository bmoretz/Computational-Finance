#include "stdafx.h"

#include "FinancialStatement.h"
#include "common.h"

using namespace std;
using namespace Fundamentals;

namespace FinancialStatementTests
{
    class FinancialStatementTests :
            public ::testing::Test
    {
    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F(FinancialStatementTests, BookExample)
    {
        auto fs = getSampleStatement();

        ASSERT_TRUE( fs.get() != nullptr );

        transferFinancialStatement( fs );

        ASSERT_TRUE( fs.get() == nullptr );
    }
}
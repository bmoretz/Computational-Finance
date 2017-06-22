#include "stdafx.h"

#include "TransactionHandler.h"
#include "FileError.h"

#include <gmock/gmock-matchers.h>

using namespace std;
using namespace Utility;

using namespace testing;

namespace UtilityTests
{
    class TransactionHandlerTests :
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

    TEST_F(TransactionHandlerTests, TestInvalidFile)
    {
        string fileName;

        try
        {
            TransactionHandler handler( fileName );
        }
        catch( const FileError &e )
        {
            EXPECT_EQ( e.what(), string("Error opening file ") );
        }
    }

    TEST_F(TransactionHandlerTests, TestBadOp)
    {
    }
}

#include "stdafx.h"

#include "common.h"
#include "TransactionHandler.h"
#include <gmock/gmock-matchers.h>
#include "FileError.h"

using namespace std;
using namespace Common;

using namespace testing;

namespace CommonTests
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

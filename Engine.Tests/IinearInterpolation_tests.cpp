#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "LinearInterpolation.h"

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
	class LinearInterpolationTests :
		public ::testing::Test
	{
	protected:
		void SetUp() override
		{
			m_x = { 10, 20, 30, 40, 49 };
			m_y = { 0.6, 0.11, 1.1, 1.62, 1.4 };
		}

		void TearDown() override
		{
		}

		vector<double> m_x, m_y;
	};

	TEST_F( LinearInterpolationTests, Example1 )
	{
		auto
			expected_value = 0.803,
			missing_point = 27.0;

		LinearInterpolation li;

		li.setPoints( m_x, m_y );

		auto actual_value = li.getValue( missing_point );

		EXPECT_EQ( expected_value, actual_value );
	}
}
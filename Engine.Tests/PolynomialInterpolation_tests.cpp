#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "PolynomialInterpolation.h"

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
	class PolynomialInterpolationTests :
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

	TEST_F( PolynomialInterpolationTests, Example1 )
	{
		auto
			expected_value = 0.795433,
			missing_point = 27.0;

		PolynomialInterpolation pi;

		pi.setPoints( m_x, m_y );

		auto actual_value = pi.getPolynomial( missing_point );

		EXPECT_DOUBLE_EQ( expected_value, round_digits( actual_value, 6 ) );
	}
}

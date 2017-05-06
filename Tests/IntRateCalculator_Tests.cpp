#include "stdafx.h"
#include "CppUnitTest.h"

#include "common.h"
#include "IntRateCalculator.h"

using namespace std;
using namespace ComputationalFinance;
using namespace FixedIncome;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FixedIncomeTets
{
	TEST_CLASS( IntRateCalculator_Tests )
	{
	public:

		// 10,000 face, 1 period at 8%
		TEST_METHOD( Test_SinglePeriodIntRate )
		{
			double rate = 0.08, face = 10000,
				expected_fv = 10800;

			{
				IntRateCalculator irCalc( rate );

				auto actual_fv = irCalc.singlePeriod( face );

				Assert::AreNotEqual( Zero, actual_fv );

				Assert::AreEqual( expected_fv, actual_fv );
			}
		}

		// $10,000 face, 4 periods, 5% rate:
		TEST_METHOD( Test_MultiplePeriodIntRate )
		{
			int periods = 4;

			double rate = 0.05, face = 10000,
				expected_fv = 12155.06;

			{
				IntRateCalculator irCalc( rate );

				auto actual_fv = irCalc.mulitplePeriod( face, periods );

				Assert::AreNotEqual( Zero, actual_fv );

				Assert::AreEqual( expected_fv, round_digits( actual_fv, 2 ) );
			}
		}

		// $10,000 face, 4 periods, 5% rate:
		TEST_METHOD( Test_ContiniousPeriodIntRate )
		{
			int periods = 4;

			double rate = 0.05, face = 10000,
				expected_fv = 12214.03;

			{
				IntRateCalculator irCalc( rate );

				auto actual_fv = irCalc.continuousCompounding( face, periods );

				Assert::AreNotEqual( Zero, actual_fv );

				Assert::AreEqual( expected_fv, round_digits( actual_fv, 2 ) );
			}
		}
	};
}
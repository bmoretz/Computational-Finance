#include "stdafx.h"
#include "CppUnitTest.h"

#include "common.h"
#include "CashflowCalculator.h"

using namespace std;
using namespace ComputationalFinance;
using namespace FixedIncome;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FixedIncomeTets
{
	TEST_CLASS( CashFlowCalculator_Tests )
	{
	public:

		// rate: 5%, values: 200, 300, 500, -1000
		TEST_METHOD( Test_CashFlowCalculator_BookExample )
		{
			double rate = 0.05, // Book erratum, example displays 5% rate, however example actually uses 8%
				expected_pv = 71.8014; // Correct EV

			{
				CashFlowCalculator cfc( rate );

				cfc.addCashPayment( 200, 1 );
				cfc.addCashPayment( 300, 2 );
				cfc.addCashPayment( 500, 3 );

				cfc.addCashPayment( -1000, 4 );

				auto actual_pv = cfc.presentValue();

				Assert::AreEqual( expected_pv, round_digits( actual_pv, 4 ) );
			}
		}

		// rate: 8%, values: $200.00 $300.00 $500.00 $1,500.00 $600.00 ($3,100.00)
		TEST_METHOD( Test_CashFlowCalculator_Example_2 )
		{
			double rate = 0.08,
				expected_pv = 396.6718; // Correct EV

			{
				CashFlowCalculator cfc( rate );

				cfc.addCashPayment( 200, 1 );
				cfc.addCashPayment( 300, 2 );
				cfc.addCashPayment( 500, 3 );
				cfc.addCashPayment( 1500, 4 );
				cfc.addCashPayment( 600, 5 );

				cfc.addCashPayment( -3100, 6 );

				auto actual_pv = cfc.presentValue();

				Assert::AreEqual( expected_pv, round_digits( actual_pv, 4 ) );
			}
		}
	};
}
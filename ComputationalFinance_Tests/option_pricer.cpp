#include "stdafx.h"

#include "common.h"
#include "OptionPricer.h"

using namespace std;
using namespace ComputationalFinance;
using namespace NumericalMethods;

namespace NumericalMethodsTests
{
	/*
	TEST_CLASS( OptionPricerTests )
	{
	public:

		TEST_METHOD( Test_OptionPricer )
		{
			auto steps = 30;

			double
				assetPrice = 60, up = 10, down = 15, rate = 0.1, strikePrice = 60,
				Expected = 2.98;

			{
				OptionPricer pricer( assetPrice, up, down, rate, steps, strikePrice );

				auto rnProb = pricer.RiskNeutProb();

				//Assert::AreNotEqual( Zero, pricer.RiskNeutProb() );
				//Assert::AreEqual( Expected, round_digits( rnProb, 3 ) );
			}
		}
	};
	*/
}
#include "stdafx.h"
#include "CppUnitTest.h"

#include "common.h"
#include "BinomialPricer.h"

using namespace std;
using namespace ComputationalFinance;
using namespace NumericalMethods;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumericalMethodsTests
{
	TEST_CLASS( BinomialPricerTests )
	{
	public:
		
		TEST_METHOD( Test_RiskNeutralProb )
		{
			double 
				price = 45, up = 10, down = 15, rate = 0.05, 
				Expected = 1.995;
			{	
				BinomialPricer pricer( 45, 10, 20, .05 );

				auto rnProb = pricer.RiskNeutProb();

				Assert::AreNotEqual( Zero, pricer.RiskNeutProb() );

				Assert::AreEqual( Expected, round_digits( rnProb, 3 ) );
			}
		}
	};
}
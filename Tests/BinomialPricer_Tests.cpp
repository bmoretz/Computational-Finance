#include "stdafx.h"
#include "CppUnitTest.h"

#include "BinomialPricer.h"

using namespace std;
using namespace NumericalMethods;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumericalMethodsTests
{	
	const double Zero = 0.0;

	inline double round_digits( double n, int digits )
	{
		return round( n * pow( 10.0, digits ) ) / pow( 10.0, digits );
	}

	TEST_CLASS( BinomialPricerTests )
	{
	public:
		
		TEST_METHOD( Test_RiskNeutralProb_1 )
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
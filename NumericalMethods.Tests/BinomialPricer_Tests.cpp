#include "stdafx.h"
#include "CppUnitTest.h"

#include "../NumericalMethods/BinomialPricer.h"

using namespace std;
using namespace NumericalMethods;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumericalMethodsTests
{	
	TEST_CLASS(BinomialPricerTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			BinomialPricer pricer;

			int result = pricer.Initialize( stringstream( "45 10 20 .005" ) );

			Assert::AreNotEqual( result, -1 );

			Assert::AreEqual( pricer.RiskNeutProb(), 0.0 );
		}
	};
}
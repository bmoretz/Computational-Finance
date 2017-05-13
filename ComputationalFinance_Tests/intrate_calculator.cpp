#include "stdafx.h"

#include "common.h"
#include "IntRateCalculator.h"

using namespace std;
using namespace ComputationalFinance;
using namespace FixedIncome;

//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace FixedIncomeTets
//{
//	TEST_CLASS( IntRateCalculator_Tests )
//	{
//	public:
//
//		// 10,000 face, 1 period at 8%
//		TEST_METHOD( Test_SinglePeriodIntRate )
//		{
//			double rate = 0.08, face = 10000,
//				expected_fv = 10800;
//
//			{
//				IntRateCalculator irCalc( rate );
//
//				auto actual_fv = irCalc.singlePeriod( face );
//
//				//Assert::AreNotEqual( Zero, actual_fv );
//				//Assert::AreEqual( expected_fv, actual_fv );
//			}
//		}
//
//		// $10,000 face, 4 periods, 5% rate:
//		TEST_METHOD( Test_MultiplePeriodIntRate )
//		{
//			auto periods = 4;
//
//			double rate = 0.05, face = 10000,
//				expected_fv = 12155.06;
//
//			{
//				IntRateCalculator irCalc( rate );
//
//				auto actual_fv = irCalc.mulitplePeriod( face, periods );
//
//				//Assert::AreNotEqual( Zero, actual_fv );
//				//Assert::AreEqual( expected_fv, round_digits( actual_fv, 2 ) );
//			}
//		}
//
//		// $10,000 face, 4 periods, 5% rate:
//		TEST_METHOD( Test_ContiniousPeriodIntRate )
//		{
//			auto periods = 4;
//
//			double rate = 0.05, face = 10000,
//				expected_fv = 12214.03;
//
//			{
//				IntRateCalculator irCalc( rate );
//
//				auto actual_fv = irCalc.continuousCompounding( face, periods );
//
//				//Assert::AreNotEqual( Zero, actual_fv );
//				//Assert::AreEqual( expected_fv, round_digits( actual_fv, 2 ) );
//			}
//		}
//
//		// $10,000 face, 4 periods, 5% rate:
//		TEST_METHOD( Test_IntRate_Logical_Methodology )
//		{
//			auto periods = 4;
//			double rate = 0.05, face = 10000;
//
//			{
//				IntRateCalculator irCalc( rate );
//
//				auto single_fv = irCalc.singlePeriod( face );
//				auto multiple_fv = irCalc.mulitplePeriod( face, periods );
//				auto continious_fv = irCalc.continuousCompounding( face, periods );
//
//				/*
//				Assert::AreNotEqual( Zero, single_fv );
//				Assert::AreNotEqual( Zero, multiple_fv );
//				Assert::AreNotEqual( Zero, continious_fv );
//
//				// Should always hold true
//				Assert::IsTrue( multiple_fv < continious_fv );
//				Assert::IsTrue( single_fv < multiple_fv );
//				Assert::IsTrue( Zero < single_fv );.
//				*/
//			}
//		}
//	};
//}
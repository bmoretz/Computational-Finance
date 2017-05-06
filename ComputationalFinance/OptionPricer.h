#pragma once

#include "stdafx.h"
#include "common.h"
#include "BinomialPricer.h"

namespace NumericalMethods {

	class OptionPricer
		: public BinomialPricer 
	{
	public:
		OptionPricer( double price, double up, double down, double rate, int steps, double strike );

		~OptionPricer();

		double PriceByCRR();
		double CallPayoff( double z );

	private:
		int m_steps;
		double m_strike;
	};
}
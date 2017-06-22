#pragma once

#include "stdafx.h"
#include "BinomialPricer.h"

using namespace NumericalMethods;

namespace Derivative
{
    class OptionPricer
            : public BinomialPricer
    {
    public:
        OptionPricer( double price, double up, double down, double rate, int steps, double strike );

        ~OptionPricer();

        double PriceByCRR() const;
        double CallPayoff( double z ) const;

    private:
        int m_steps;
        double m_strike;
    };
}

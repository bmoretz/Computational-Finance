#pragma once

using namespace std;

namespace FixedIncome
{
    class BondCalculator
    {
    public:
        BondCalculator( string instution, double principal, double coupon, int numPeriods );
        BondCalculator( const BondCalculator &v );
        BondCalculator& operator=( const BondCalculator &v );
        ~BondCalculator();

        double interestRate() const;

    private:
        string m_instution;
        double m_principal, m_coupon;
        int m_numPeriods;
    };
}

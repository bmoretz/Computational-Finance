#pragma once

using namespace std;

namespace Instruments
{
    class BondInstrument
    {
    public:
        BondInstrument();
        BondInstrument( double monthlyPayment, double principal );
        BondInstrument( const BondInstrument &b );
        BondInstrument& operator=( const BondInstrument &b );
        ~BondInstrument();

        double getMonthlyPayment() const;
        double getPrincipal() const;

    protected:
        double m_monthlyPayment, m_principal;
    };

    class MortgageInstrument
    {
    public:
        MortgageInstrument();
        MortgageInstrument( double monthlyPayment, double propertyValue, double m_downPayment );
        MortgageInstrument( const MortgageInstrument &b );
        MortgageInstrument& operator=( const MortgageInstrument &b );
        ~MortgageInstrument();

        double getMonthlyPayment() const;
        double getPrincipal() const;

    protected:
        double m_monthlyPayment, m_propertyValue, m_downPayment;
    };
}

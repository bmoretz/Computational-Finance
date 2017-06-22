#include "stdafx.h"
#include "InvestmentInstrument.h"

namespace Instruments
{
    #pragma region Constructor / Deconstructor

    BondInstrument::BondInstrument()
        : m_monthlyPayment( 0 ),
          m_principal( 0 )
    {
    }

    BondInstrument::BondInstrument( double monthlyPayment, double principal )
        : m_monthlyPayment( monthlyPayment ),
          m_principal( principal )
    {
    }

    BondInstrument::BondInstrument( const BondInstrument &i )
    {
        m_monthlyPayment = i.m_monthlyPayment;
        m_principal = i.m_principal;
    }

    BondInstrument& BondInstrument::operator=( const BondInstrument &i )
    {
        if( this != &i )
        {
            m_monthlyPayment = i.m_monthlyPayment;
            m_principal = i.m_principal;
        }

        return *this;
    }

    BondInstrument::~BondInstrument()
    {
    }

    #pragma endregion

    double BondInstrument::getMonthlyPayment() const
    {
        return m_monthlyPayment;
    }

    double BondInstrument::getPrincipal() const
    {
        return m_principal;
    }

    #pragma region Constructor / Deconstructor

    MortgageInstrument::MortgageInstrument()
        : m_monthlyPayment( 0 ),
          m_propertyValue( 0 ),
          m_downPayment( 0 )
    {
    }

    MortgageInstrument::MortgageInstrument( double monthlyPayment, double propertyValue, double m_downPayment )
        : m_monthlyPayment( monthlyPayment ),
          m_propertyValue( propertyValue ),
          m_downPayment( m_downPayment )
    {
    }

    MortgageInstrument::MortgageInstrument( const MortgageInstrument &i )
    {
        m_monthlyPayment = i.m_monthlyPayment;
        m_propertyValue = i.m_propertyValue;
        m_downPayment = i.m_downPayment;
    }

    MortgageInstrument& MortgageInstrument::operator=( const MortgageInstrument &i )
    {
        if( this != &i )
        {
            m_monthlyPayment = i.m_monthlyPayment;
            m_propertyValue = i.m_propertyValue;
            m_downPayment = i.m_downPayment;
        }

        return *this;
    }

    MortgageInstrument::~MortgageInstrument()
    {
    }

    #pragma endregion

    double MortgageInstrument::getMonthlyPayment() const
    {
        return m_monthlyPayment;
    }

    double MortgageInstrument::getPrincipal() const
    {
        return m_propertyValue - m_downPayment;
    }
}

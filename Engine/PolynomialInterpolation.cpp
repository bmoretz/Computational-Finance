#include "stdafx.h"
#include "PolynomialInterpolation.h"

using namespace std;

namespace NumericalMethods
{
    #pragma region Constructor / Deconstructor

    PolynomialInterpolation::PolynomialInterpolation()
        : m_x( 0 ),
          m_y( 0 )
    {
    }

    PolynomialInterpolation::PolynomialInterpolation( const PolynomialInterpolation &p )
        : m_x( p.m_x ),
          m_y( p.m_y )
    {
    }

    PolynomialInterpolation& PolynomialInterpolation::operator=( const PolynomialInterpolation &p )
    {
        if( this != &p )
        {
            m_x = p.m_x;
            m_y = p.m_y;
        }

        return *this;
    }

    PolynomialInterpolation::~PolynomialInterpolation()
    {
    }

    #pragma endregion

    void PolynomialInterpolation::setPoints( const std::vector<double> &x, const std::vector<double> &y )
    {
        m_x = x;
        m_y = y;
    }

    double PolynomialInterpolation::getPolynomial( double x )
    {
        auto polynomialValue = 0.0;

        for( size_t i = 0; i < m_x.size(); ++i )
        {
            auto numerator = 1.0;

            for( auto j = 0; j < m_x.size(); ++j )
            {
                if( j != i )
                {
                    numerator *= x - m_x[ j ];
                }
            }

            auto denominator = 1.0;

            for( auto j = 0; j < m_y.size(); ++j )
            {
                if( j != i )
                {
                    denominator *= m_x[ i ] - m_x[ j ];
                }
            }

            polynomialValue += m_y[ i ] * ( numerator / denominator );
        }

        return polynomialValue;
    }
}

#include "stdafx.h"
#include "LinearInterpolation.h"

using namespace std;

namespace NumericalMethods
{
    #pragma region Constructor / Deconstructor

    LinearInterpolation::LinearInterpolation()
        : m_y( 0 ),
          m_x( 0 )
    {
    }

	LinearInterpolation& LinearInterpolation::operator=( const LinearInterpolation &l )
    {
        if( this != &l )
        {
            m_x = l.m_x;
            m_y = l.m_y;
        }

        return *this;
    }

    #pragma endregion

    void LinearInterpolation::setPoints( const std::vector<double> &x_vals, const std::vector<double> &y_vals )
    {
        m_x = x_vals;
        m_y = y_vals;

        sort( m_x.begin(), m_x.end() );

        for( auto i = 0; i < m_x.size(); ++i )
        {
            for( auto j = 0; j < m_y.size(); ++j )
            {
                if( m_x[ i ] == x_vals[ j ] )
                {
                    m_y[ i ] = y_vals[ j ];

                    break;
                }
            }
        }
    }

    double LinearInterpolation::getValue( const double x )
    {
        auto x0 = 0.0, x1 = 0.0, y0 = 0.0, y1 = 0.0;

        if( x < m_x[ 0 ] || x > m_x[ m_x.size() - 1 ] )
        {
            return 0.0;
        }

        for( auto i = 0; i < m_x.size(); ++i )
        {
            if( m_x[ i ] < x )
            {
                x0 = m_x[ i ];
                y0 = m_y[ i ];
            }
            else if( m_x[ i ] >= x )
            {
                x1 = m_x[ i ];
                y1 = m_y[ i ];
            }
        }

        return y0 * ( x - x1 ) / ( x0 - x1 ) + y1 * ( x - x0 ) / ( x1 - x0 );
    }
}

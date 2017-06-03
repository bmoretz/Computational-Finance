#pragma once

#include "stdafx.h"
#include <algorithm>
#include <numeric>

#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

using namespace std;

namespace Common
{
    template <typename T>
    T square( const T value )
    {
        return value * value;
    }

    const double Zero = 0.0;

    template<typename T>
    T round_digits( T n, int digits )
    {
        return round( n * pow( 10.0, digits ) ) / pow( 10.0, digits );
    }

    inline vector<double> round_digits( const vector<double> &in, const int digits )
    {
        vector<double> out;

        out.reserve( in.size() );

        transform( in.begin(), in.end(), back_inserter( out ), [digits]( double v ) -> double { return round_digits( v, digits ); } );

        return out;
    }

    template <typename T>
    T mean( vector<T> n )
    {
        if( n.size() == 0 )
            return Zero;

        return accumulate( n.begin(), n.end(), 0.0 ) / n.size();
    }
}
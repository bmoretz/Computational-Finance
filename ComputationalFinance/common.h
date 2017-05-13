#pragma once

#include "stdafx.h"

#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

inline int square(const int value)
{
	return value * value;
}

namespace ComputationalFinance
{
	const double Zero = 0.0;

	inline double round_digits( double n, int digits )
	{
		return round( n * pow( 10.0, digits ) ) / pow( 10.0, digits );
	}
}
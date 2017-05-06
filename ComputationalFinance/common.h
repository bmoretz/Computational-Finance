#pragma once

#include "stdafx.h"

namespace ComputationalFinance
{
	const double Zero = 0.0;

	inline double round_digits( double n, int digits )
	{
		return round( n * pow( 10.0, digits ) ) / pow( 10.0, digits );
	}
}
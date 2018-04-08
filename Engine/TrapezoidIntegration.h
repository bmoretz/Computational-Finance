#pragma once

#include "MathFunction.h"

namespace NumericalMethods
{
	class TrapezoidIntegration
	{
	public:
		explicit TrapezoidIntegration( MathFunction<double> &f );
		explicit TrapezoidIntegration( const TrapezoidIntegration &t );
		~TrapezoidIntegration();

		TrapezoidIntegration& operator=( const TrapezoidIntegration &t );

		void setNumIntervals( const int n );

		double getIntegral( double a, double b ) const;

	private:
		MathFunction<double> &m_f;
		int m_numIntervals;
	};
}
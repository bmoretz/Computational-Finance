#pragma once

#include "MathFunction.h"

namespace NumericalMethods
{
	class SimpsonsIntegraion
	{
	public:
		explicit SimpsonsIntegraion( MathFunction<double> &f );
		explicit SimpsonsIntegraion( const SimpsonsIntegraion &t );
		~SimpsonsIntegraion();

		SimpsonsIntegraion& operator=( const SimpsonsIntegraion &t );

		void setNumIntervals( const int n );

		double getIntegral( double a, double b ) const;

	private:
		MathFunction<double> &m_f;
		int m_numIntervals;
	};
}
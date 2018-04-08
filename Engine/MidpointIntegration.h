#pragma once

#include "MathFunction.h"

namespace NumericalMethods
{
	class MidpointIntegration
	{
	public:
		explicit MidpointIntegration( MathFunction<double> &f );
		explicit MidpointIntegration( const MidpointIntegration &mp );
		~MidpointIntegration();

		MidpointIntegration& operator=( const MidpointIntegration &mp );

		void setNumIntervals( const int n );

		double getIntegral( double a, double b ) const;

	private:
		MathFunction<double> &m_f;
		int m_numIntervals;
	};
}

#pragma once

#include "MathFunction.h"

namespace NumericalMethods
{
	class RungeKuttaMethod
	{
	public:
		explicit RungeKuttaMethod( MathFunction<double> &f );
		RungeKuttaMethod( const RungeKuttaMethod &p ) = default;
		~RungeKuttaMethod() = default;
		RungeKuttaMethod& operator=( const RungeKuttaMethod &p );

		double solve( int n, double x0, double y0, double c ) const;

	private:
		MathFunction<double> &m_f;
	};
}
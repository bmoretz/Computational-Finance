#pragma once

#include "MathFunction.h"

namespace NumericalMethods
{
	class EulersMethod
	{
	public:
		explicit EulersMethod( MathFunction<double> &f );
		EulersMethod( const EulersMethod &p ) = default;
		~EulersMethod() = default;
		EulersMethod& operator=( const EulersMethod &p );

		double solve( int n, double x0, double y0, double c ) const;

	private:
		MathFunction<double> &m_f;
	};
}

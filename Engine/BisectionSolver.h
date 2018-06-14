#pragma once

template <class T>
class MathFunction;

namespace NumericalMethods
{
	class BisectionSolver
	{
	public:
		explicit BisectionSolver( MathFunction<double> &f );
		explicit BisectionSolver( const BisectionSolver &p );
		~BisectionSolver() = default;

		BisectionSolver& operator=( const BisectionSolver &p );
		double getRoot( double x1, double x2 ) const;

	private:
		MathFunction<double> &m_f;
		double m_error;
	};
}

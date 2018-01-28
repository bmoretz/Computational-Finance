#pragma once

template <class T>
class MathFunction;

namespace NumericalMethods
{
	class SecantSolver
	{
	public:
		explicit SecantSolver( MathFunction<double> &f );
		explicit SecantSolver( const SecantSolver &p );
		~SecantSolver();

		SecantSolver& operator=( const SecantSolver &p );
		double getRoot( double x1, double x2 ) const;

	private:
		MathFunction<double> &m_f;
		double m_error;
	};
}

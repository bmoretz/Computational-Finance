#pragma once

template <class T>
class MathFunction;

namespace NumericalMethods
{
	class NewtonSolver
	{
	public:
		explicit NewtonSolver( MathFunction<double> &f, MathFunction<double> &d );
		explicit NewtonSolver( const NewtonSolver &p );
		~NewtonSolver();

		NewtonSolver& operator=( const NewtonSolver &p );
		double getRoot( double x0 ) const;

	private:
		MathFunction<double> &m_f;
		MathFunction<double> &m_derivative;
		double m_error;
	};
}

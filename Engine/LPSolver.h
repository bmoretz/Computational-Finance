#pragma once

#include "stdafx.h"
#include "LPSolver.h"
#include "Matrix.h"

#include <vector>
#include <string>

#include <glpk.h>

struct glp_prob;

namespace NumericalMethods
{
	class LPSolver
	{
	public:
		explicit LPSolver( const Matrix &m, std::vector<double> b, std::vector<double> c );
		LPSolver( const LPSolver &p ) = default;
		LPSolver& operator=( const LPSolver &p );

		virtual ~LPSolver();

		enum ResultType
		{
			INFEASIBLE,
			FEASIBLE,
			ERRORED
		};

		void SetName( const std::string &s ) const;
		bool isValid() const;

		void setMaximization() const;
		void setMinimization() const;
		ResultType solve( std::vector<double> &result, double &objValue ) const;

	private:
		size_t m_M;
		size_t m_N;

		std::vector<double> m_c;
		std::vector<double> m_b;

		Matrix m_A;

		glp_prob *m_lp;

		void initProblem( size_t M, size_t N );
		void setRowBounds();
		void setColumnCoefs();

	protected:
		glp_prob* getLP() const;
		int getNumCols() const;
		int getNumRows() const;
	};
}

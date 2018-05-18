#include "stdafx.h"
#include "LPSolver.h"
#include <utility>

using namespace std;

namespace NumericalMethods
{
	LPSolver::LPSolver( const Matrix &m, std::vector<double> b, std::vector<double> c )
		: m_M( m.numRows() ),
		m_N( m.getRows()[ 0 ].size() ),
		m_c( std::move( c ) ),
		m_b( std::move( b ) ),
		m_A( m ),
		m_lp( glp_create_prob() )
	{
		initProblem( m_M, m_N );
	}

	LPSolver::~LPSolver()
	{
		glp_delete_prob( m_lp );
	}

	LPSolver& LPSolver::operator=( const LPSolver &p )
	{
		if( this != &p )
		{
			m_lp = p.m_lp;
			m_M = p.m_M;
			m_N = p.m_N;
			m_c = p.m_c;
			m_b = p.m_b;
			m_A = p.m_A;

			m_lp = glp_create_prob();
			initProblem( m_N, m_N );
		}

		return *this;
	}

	void LPSolver::SetName( const std::string &s ) const
	{
		glp_set_prob_name( m_lp, s.c_str() );
	}

	bool LPSolver::isValid() const
	{
		return m_lp != nullptr;
	}

	void LPSolver::setMaximization() const
	{
		glp_set_obj_dir( m_lp, GLP_MAX );
	}

	void LPSolver::setMinimization() const
	{
		glp_set_obj_dir( m_lp, GLP_MIN );
	}

	LPSolver::ResultType LPSolver::solve( std::vector<double> &result, double &objValue ) const
	{
		glp_simplex( m_lp, nullptr );

		result.resize( m_N, 0 );

		objValue = glp_get_obj_val( m_lp );

		for( auto j = 0; j < m_N; ++j )
		{
			result[ j ] = glp_get_col_prim( m_lp, j + 1 );
		}

		return ResultType::FEASIBLE;
	}

	void LPSolver::initProblem( const size_t M, const size_t N )
	{
		if( !m_lp ) return;

		setRowBounds();
		setColumnCoefs();

		vector<int> I, J;
		vector<double> V;

		// Indices in GLPK start on 1
		I.push_back( 0 );
		J.push_back( 0 );
		V.push_back( 0 );

		for( auto i = 0; i < M; ++i )
		{
			for( auto j = 0; j < N; ++j )
			{
				I.push_back( i + 1 );
				J.push_back( j + 1 );
				V.push_back( m_A[ i ][ j ] );
			}
		}

		glp_load_matrix( m_lp, static_cast<int>( m_M * m_N ), &I[ 0 ], &J[ 0 ], &V[ 0 ] );
	}

	void LPSolver::setRowBounds()
	{
		glp_add_rows( m_lp, m_M );
		for( auto i = 0; i < m_N; ++i )
		{
			glp_set_row_bnds( m_lp, i + 1, GLP_UP, 0.0, m_b[ i ] );
		}
	}

	void LPSolver::setColumnCoefs()
	{
		glp_add_cols( m_lp, static_cast<int>( m_N ) );

		for( auto j = 0; j < m_N; ++j )
		{
			glp_set_col_bnds( m_lp, j + 1, GLP_LO, 0.0, 0.0 );
			glp_set_obj_coef( m_lp, j + 1, m_c[ j ] );
		}
	}

	glp_prob* LPSolver::getLP() const
	{
		return m_lp;
	}

	int LPSolver::getNumCols() const
	{
		return static_cast<int>( m_N );
	}

	int LPSolver::getNumRows() const
	{
		return static_cast<int>( m_M );
	}
}

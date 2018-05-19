#include "stdafx.h"
#include "RandomWalk.h"

using namespace std;

namespace NumericalMethods
{
	RandomWalk::RandomWalk( const int size, const double start, const double step )
		: m_size( size ),
		m_start( start ),
		m_step( step )
	{
	}

	RandomWalk& RandomWalk::operator=( const RandomWalk &p )
	{
		if( this != &p )
		{
			m_size = p.m_size;
			m_start = p.m_start;
			m_step = p.m_step;
		}

		return *this;
	}

	vector<double> RandomWalk::getWalk() const
	{
		vector<double> walk;
		auto prev = m_start;

		for( auto index = 0; index < m_size; ++index )
		{
			const auto r = rand() % 3;

			auto val = prev;

			if( r == 0 ) val += ( m_step * val );
			else if( r == 1 ) val -= ( m_step * val );

			walk.push_back( val );
			prev = val;
		}

		return walk;
	}
}

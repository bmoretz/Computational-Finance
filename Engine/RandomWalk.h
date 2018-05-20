#pragma once

#include <vector>

namespace NumericalMethods
{
	class RandomWalk
	{
	public:

		explicit RandomWalk( int size, double start, double step );
		RandomWalk( const RandomWalk &p ) = default;
		~RandomWalk() = default;
		RandomWalk& operator=( const RandomWalk &p );

		std::vector<double> getWalk() const;

	private:
		int m_size;
		double m_start, m_step;
	};
}
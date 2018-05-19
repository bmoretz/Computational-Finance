#include "stdafx.h"
#include "OptionProbabilities.h"

#include <boost/random/normal_distribution.hpp>
#include <boost/random.hpp>

using std::vector;


namespace Derivative
{
	static boost::rand48 random_generator;

	namespace
	{
		const int NUM_ITERATIONS = 1000;
	}

	OptionProbabilities::OptionProbabilities( const double initialPrice, const double strike, const double avgStep,
											const int nDays )
		: m_initialPrice( initialPrice ),
		m_strike( strike ),
		m_avgStep( avgStep ),
		m_numDays( nDays ),
		m_numIterations( NUM_ITERATIONS )
	{
	}

	OptionProbabilities& OptionProbabilities::operator=( const OptionProbabilities &p )
	{
		if( this != &p )
		{
			m_numIterations = p.m_numIterations;
			m_avgStep = p.m_avgStep;
			m_initialPrice = p.m_initialPrice;
			m_numDays = p.m_numDays;
			m_strike = p.m_strike;
		}

		return *this;
	}

	double OptionProbabilities::probFinishAboveStrike() const
	{
		auto nAbove = 0;

		for( auto index = 0; index < m_numIterations; ++index )
		{
			const auto val = getLastPriceOfWalk();

			if( val >= m_strike )
			{
				nAbove++;
			}
		}

		return nAbove / static_cast<double>( m_numIterations );
	}

	double OptionProbabilities::probFinishBelowStrike() const
	{
		auto nBelow = 0;

		for( auto index = 0; index < m_numIterations; ++index )
		{
			const auto val = getLastPriceOfWalk();

			if( val <= m_strike )
			{
				nBelow++;
			}
		}

		return nBelow / static_cast<double>( m_numIterations );
	}

	double OptionProbabilities::probFinalPriceBetweenPrices( const double lowPrice, const double highPrice ) const
	{
		auto nBetween = 0;

		for( auto index = 0; index < m_numIterations; ++index )
		{
			const auto val = getLastPriceOfWalk();

			if( lowPrice <= val && val <= highPrice )
			{
				nBetween++;
			}
		}

		return nBetween / static_cast<double>( m_numIterations );
	}

	std::vector<double> OptionProbabilities::getWalk() const
	{
		vector<double> walk;
		auto prev = m_initialPrice;

		for( auto index = 0; index < m_numDays; ++index )
		{
			const auto stepSize = gaussianValue( 0, m_avgStep );
			const auto r = rand() % 2;
			auto val = prev;

			if( r == 0 ) val += ( stepSize * val );
			else val -= ( stepSize * val );

			walk.push_back( val );
			prev = val;
		}

		return walk;
	}

	double OptionProbabilities::gaussianValue( const double mean, const double sigma )
	{
		boost::random::normal_distribution<> distrib( mean, sigma );

		return distrib( random_generator );
	}

	double OptionProbabilities::getLastPriceOfWalk() const
	{
		auto prev = m_initialPrice;

		for( auto index = 0; index < m_numDays; ++index )
		{
			const auto stepSize = gaussianValue( 0, m_avgStep );

			const auto r = rand() % 2;

			auto val = prev;

			if( r == 0 ) val += ( stepSize * val );
			else val -= ( stepSize * val );

			prev = val;
		}

		return prev;
	}
}

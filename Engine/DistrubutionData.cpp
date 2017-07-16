#include "stdafx.h"
#include "DistrubutionData.h"

using namespace boost::math;

namespace NumericalMethods
{
    #pragma region Constructor / Deconstructor

    DistrubutionData::DistrubutionData()
    {
    }


    DistrubutionData::~DistrubutionData()
    {
    }

    #pragma endregion

    static boost::rand48 random_generator;

    vector<double> DistrubutionData::gaussianData( int nPoints, double mean, double sigma )
    {
        vector<double> data;

        auto distrubution = boost::random::normal_distribution<>( mean, sigma );

        for( auto index = 0; index < nPoints; ++index )
        {
            data.push_back( distrubution( random_generator ) );
        }

        return data;
    }

    vector<double> DistrubutionData::exponentialData( int nPoints, double rate )
    {
        vector<double> data;

        auto distrubution = boost::random::exponential_distribution<>( rate );

        for( auto index = 0; index < nPoints; ++index )
        {
            data.push_back( distrubution( random_generator ) );
        }

        return data;
    }

    vector<double> DistrubutionData::chiSquaredData( int nPoints, double degreesOfFreedom )
    {
        vector<double> data;

        auto distrubution = boost::random::chi_squared_distribution<>( degreesOfFreedom );

        for( auto index = 0; index < nPoints; ++index )
        {
            data.push_back( distrubution( random_generator ) );
        }

        return data;
    }

    vector<double> DistrubutionData::logNormalData( int nPoints, double mean, double sigma )
    {
        vector<double> data;

        auto distrubution = boost::random::lognormal_distribution<>( mean, sigma );

        for( auto index = 0; index < nPoints; ++index )
        {
            data.push_back( distrubution( random_generator ) );
        }

        return data;
    }

    double DistrubutionData::gaussianQuantile( double x, double mean, double sigma ) const
    {
        normal_distribution<> dist( mean, sigma );

        return quantile( dist, x );
    }

    double DistrubutionData::chiSquaredQuantile( double x, int degreesOfFreedom ) const
    {
        chi_squared_distribution<> dist( degreesOfFreedom );

        return quantile( dist, x );
    }

    double DistrubutionData::exponentialQuantile( double x, double rate ) const
    {
        exponential_distribution<> dist( rate );

        return quantile( dist, x );
    }

    double DistrubutionData::logNormalQuantile( double x, double mean, double sigma ) const
    {
        lognormal_distribution<> dist( mean, sigma );

        return quantile( dist, x );
    }
}
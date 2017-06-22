#pragma once

using namespace std;

namespace NumericalMethods
{
    class DistrubutionData
    {
    public:
        DistrubutionData();
        ~DistrubutionData();

        static vector<double> gaussianData( int nPoints, double mean, double sigma );
        static vector<double> exponentialData( int nPoints, double rate );
        static vector<double> chiSquaredData( int nPoints, double degreesOfFreedom );
        static vector<double> logNormalData( int nPoints, double mean, double sigma );

        double gaussianQuantile( double x, double mean, double sigma ) const;
        double chiSquaredQuantile( double x, int degreesOfFreedom ) const;
        double exponentialQuantile( double x, double rate ) const;
        double logNormalQuantile( double x, double mean, double sigma ) const;
    };

    template<class T>
    void printData( const string &label, const T &data )
    {
        cout << " " << label << ":    ";

        for( auto i : data )
        {
            cout << i << " ";
        }

        cout << endl;
    };
};
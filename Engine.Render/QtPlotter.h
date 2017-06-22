#pragma once

using namespace std;

namespace Rendering
{
    class QtPlotter
    {
    public:
        QtPlotter();
        QtPlotter( const QtPlotter &q );
        QtPlotter& operator=( const QtPlotter &q );
        ~QtPlotter();

        void setData( const vector<double> &xdata, const vector<double> &ydata );
        static int plotWindowRun();

    protected:
        vector<double> m_xdata, m_ydata;
    };
}

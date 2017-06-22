#pragma once

using namespace std;

namespace Utility
{
    class GnuplotPlotter
    {
    public:
        explicit GnuplotPlotter( const string &fileName );
        GnuplotPlotter( const GnuplotPlotter& plotter );
        GnuplotPlotter& operator=( const GnuplotPlotter &plotter );
        ~GnuplotPlotter();
    
        void generateCmds( const string &cmdFileName ) const;
        void setHeaders( const string &xheader, const string &yheader );
        void setData( const vector<double> &xdata, const vector<double> & ydata );
        void setData( const vector<string> &xdata, const vector<double> &ydata );
        void csvWrite();

    protected:
        string m_fileName;
        string m_xheader, m_yheader;
        vector<string> m_xdata;
        vector<double> m_ydata;
        bool m_isDate;
    };
}
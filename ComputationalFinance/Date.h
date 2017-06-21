#pragma once

using namespace std;
using namespace boost::gregorian;

namespace Common
{
    class Date
    {
    public:

        enum DayOfWeek
        {
            UNKNOWN,

            Sun,
            Mon,
            Tue,
            Wed,
            Thu,
            Fri,
            Sat
        };

        Date( int year, int month, int day );
        ~Date();


        bool isLeapYear() const;
        
        Date& operator++();
        bool operator<( const Date &d ) const;
        DayOfWeek getDayOfWeek() const;
        int daysInterval( const Date &d ) const;
        bool isTradingDay() const;

        static string toStringDate( DayOfWeek day );

    protected:
        int m_year, m_month, m_day;
    };
}
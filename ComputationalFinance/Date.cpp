#include "stdafx.h"
#include "Date.h"

namespace Common
{
    #pragma region Constructor / Deconstrutor

    Date::Date( int year, int month, int day )
        : m_year( year ),
          m_month( month ),
          m_day( day )
    {
    }

    Date::~Date()
    {
    }

    #pragma endregion

    bool Date::isLeapYear() const
    {
        if( m_year % 4 != 0 ) return false;
        if( m_year % 100 != 0 ) return false;
        if( m_year % 400 != 0 ) return false;

        return true;
    }

    Date& Date::operator++()
    {
        vector<int> monthsWith31 = { 1, 3, 5, 7, 8, 10, 12 };

        if( m_day == 31 )
        {
            m_day = 1;
            m_month++;
        }
        else if( m_day == 30 &&
            find( monthsWith31.begin(), monthsWith31.end(), m_month ) == monthsWith31.end() )
        {
            m_day = 1;
            m_month++;
        }
        else if( m_day == 29 && m_month == 2 )
        {
            m_day = 1;
            m_month++;
        }
        else if( m_day == 28 && m_month == 2 && !isLeapYear() )
        {
            m_day = 1;
            m_month++;
        }
        else
        {
            m_day++;
        }

        if( m_month > 12 )
        {
            m_month = 1;
            m_year++;
        }

        return *this;
    }

    bool Date::operator<( const Date &d ) const
    {
        if( m_year < d.m_year ) return true;
        if( m_year == d.m_year && m_month < d.m_month ) return true;
        if( m_year == d.m_year && m_month == d.m_month && m_day < d.m_day ) return true;

        return false;
    }

    Date::DayOfWeek Date::getDayOfWeek() const
    {
        auto day = 1;
        Date d( 1900, 1, 1 );

        for( ; d < *this; ++d )
        {
            if( day == 7 ) day = 1;
            else day++;
        }

        return static_cast<DayOfWeek>( day );
    }

    int Date::daysInterval( const Date &d ) const
    {
        date bdate1( m_year, m_month, m_day );
        date bdate2( d.m_year, d.m_month, d.m_day );

        auto duration = bdate1 - bdate2;

        return static_cast<int>( duration.days() );
    }

    bool Date::isTradingDay() const
    {
        auto dayOfWeek = getDayOfWeek();

        if( dayOfWeek == Sun || dayOfWeek == Sat )
        {
            return false;
        }

        return true;
    }

    string Date::toStringDate( DayOfWeek day )
    {
        switch( day )
        {
            case Sun: return "Sunday";
            case Mon: return "Monday";
            case Tue: return "Tuesday";
            case Wed: return "Wednesday";
            case Thu: return "Thrusday";
            case Fri: return "Friday";
            case Sat: return "Saturday";

            default:
                break;
        }

        throw runtime_error( "Unknown day of week" );
    }
}

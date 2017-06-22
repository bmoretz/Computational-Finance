#pragma once

#include <boost/ratio/ratio.hpp>

namespace NumericalMethods
{
    typedef boost::ratio<1, 1>::type CalmarRatioType;
    typedef boost::ratio<1, 100>::type CalmarRatioBPS;
    typedef boost::ratio<1, 1>::type CalmarRatioPerc;

    template <class Ratio>
    class CalmarRatio
    {
    public:
        CalmarRatio( double calmar, double ret )
            : m_calmar( calmar ),
              m_return( ret )
        {
        }

        virtual ~CalmarRatio();

        double getReturn() const
        {
            return m_return;
        }

        double getDrawDown() const
        {
            return m_return / m_calmar * m_ratio.den;
        }

    private:
        Ratio m_ratio;
        double m_calmar, m_return;
    };

    template <class Ratio>
    CalmarRatio<Ratio>::~CalmarRatio()
    {
    }

    template<>
    inline double CalmarRatio<CalmarRatioBPS>::getDrawDown() const
    {
        return m_return / m_calmar * m_ratio.den * 100;
    }
}

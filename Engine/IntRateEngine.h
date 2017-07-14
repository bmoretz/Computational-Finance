#pragma once

namespace FixedIncome
{
    template <class T>
    class IntRateEngine
    {
    public:
        IntRateEngine();
        IntRateEngine( const IntRateEngine<T> &ire );
        IntRateEngine<T>& operator=( const IntRateEngine<T> &ire );
        ~IntRateEngine();

        void setInstrument( T &inv );

        double getAnnualIntRate();

    private:
        T m_instrument;
    };

    template <class T>
    IntRateEngine<T>::IntRateEngine()
    {
    }

    template <class T>
    IntRateEngine<T>::IntRateEngine( const IntRateEngine &ire )
    {
        m_instrument = ire.m_instrument;
    }

    template <class T>
    IntRateEngine<T>& IntRateEngine<T>::operator=( const IntRateEngine &ire )
    {
        if( this != &ire )
        {
            m_instrument = ire.m_instrument;
        }

        return *this;
    }

    template <class T>
    IntRateEngine<T>::~IntRateEngine()
    {
    }

    template <class T>
    void IntRateEngine<T>::setInstrument( T &inv )
    {
        m_instrument = inv;
    }

    template <class T>
    double IntRateEngine<T>::getAnnualIntRate()
    {
        auto payment = m_instrument.getMonthlyPayment();
        auto principal = m_instrument.getPrincipal();

        return ( 12 * payment ) / principal;
    }
}

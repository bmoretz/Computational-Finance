#include "stdafx.h"
#include "CreditRisk.h"

namespace Common
{
    #pragma region Constructor / Deconstructor

    CreditRisk::CreditRisk( RiskType r )
        : m_raiting( r )
    {
    }

    CreditRisk::CreditRisk( const CreditRisk &c )
    {
        m_raiting = c.m_raiting;
    }

    CreditRisk & CreditRisk::operator=( const CreditRisk &c )
    {
        if( this != &c )
        {
            m_raiting = c.m_raiting;
        }

        return *this;
    }

    CreditRisk::~CreditRisk()
    {
    }

    #pragma endregion

    CreditRisk::RiskType CreditRisk::getRaiting() const
    {
        return m_raiting;
    }
}

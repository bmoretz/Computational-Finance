#pragma once

#include "common.h"

using namespace std;

namespace Common
{
    class CreditRisk
    {
    public:
        enum RiskType
        {
            UNKNOWN = 0,

            AAA,
            AAPlus,
            AA,
            APlus,
            A,
            BPlus,
            B,
            CPlus,
            C
        };

        explicit CreditRisk( RiskType r );
        CreditRisk( const CreditRisk &c );
        CreditRisk& operator=( const CreditRisk &c );
        ~CreditRisk();

        RiskType getRaiting() const;

    protected:
        RiskType m_raiting;
    };
}

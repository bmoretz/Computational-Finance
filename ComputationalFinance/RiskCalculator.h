#pragma once

#include "common.h"
#include "CreditRisk.h"

using namespace std;
using namespace Common;

namespace Common
{
    class RiskCalculator
    {
    public:
        RiskCalculator();
        RiskCalculator( const RiskCalculator &c );
        RiskCalculator& operator=( const RiskCalculator &c );
        ~RiskCalculator();

        void addCreditRisk( shared_ptr<CreditRisk> risk );

        CreditRisk::RiskType portfolioMaxRisk() const;
        CreditRisk::RiskType portfolioMinRisk() const;

    private:
        vector<shared_ptr<CreditRisk>> m_creditRisks;
    };
}

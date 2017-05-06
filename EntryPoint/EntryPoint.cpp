#include "stdafx.h"

#include "BinomialPricer.h"

using namespace std;
using namespace NumericalMethods;

int main()
{
	cout << "Enter: Price, Up, Down and Rate:";

	double price, up, down, rate;

	if( !( cin >> price >> up >> down >> rate ) )
		return -1;

	BinomialPricer pricer( price, up, down, rate );

	cout << "Risk-Neutral Probability: " << pricer.RiskNeutProb();

	cout << std::endl << "Press any key" << std::endl;
	cin.ignore();
	string temp;
	cin >> temp;

    return 0;
}
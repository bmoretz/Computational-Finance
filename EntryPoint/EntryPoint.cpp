// EntryPoint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../NumericalMethods/BinomialPricer.h"

using namespace std;
using namespace NumericalMethods;

int main()
{
	BinomialPricer pricer;

	cout << "Enter: Price, Up, Down and Rate:";

	pricer.Initialize( std::cin );

	cout << "Risk-Neutral ProbabilityL: " << pricer.RiskNeutProb();

	cout << std::endl << "Press any key" << std::endl;
	cin.ignore();
	string temp;
	cin >> temp;

    return 0;
}
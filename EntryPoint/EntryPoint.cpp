#include "stdafx.h"

#include "DistrubutionData.h"

using namespace std;
using namespace NumericalMethods;

int main()
{
    auto normal = DistrubutionData::gaussianData( 10, 0, 1 );

    printData( "Normal", normal );
    
    // Wait
	cout << endl << "Press any key" << endl;
	cin.ignore();
	string temp;
	cin >> temp;
    
    return 0;
}
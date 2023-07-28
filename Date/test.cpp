#include <iostream>
#include "Date.h"
using namespace std;




int main()
{
	Date d1(2021, 3, 1);
	Date d2(2020, 6, 9);
	d1 = d1 - 1;
	d1.Print();
	//d1 = d1 + 759;
	//d1.Print();
	cout << d1 - d2 << endl;
	cout << (bool)(d1 > d2) << endl;
	cout << (bool)(d1 < d2) << endl;
	cout << (bool)(d1 >= d2) << endl;
	cout << (bool)(d1 <= d2) << endl;
	cout << (bool)(d1 == d2) << endl;

	return 0;
}





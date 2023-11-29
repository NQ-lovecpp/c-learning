#include <iostream>
#include <string.h>
#include "Date.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;




//int main()
//{
//	Date d1(2021, 3, 1);
//	Date d2(2020, 6, 9);
//	d1 = d1 - 1;
//	d1.Print();
//	//d1 = d1 + 759;
//	//d1.Print();
//	cout << d1 - d2 << endl;
//	cout << (bool)(d1 > d2) << endl;
//	cout << (bool)(d1 < d2) << endl;
//	cout << (bool)(d1 >= d2) << endl;
//	cout << (bool)(d1 <= d2) << endl;
//	cout << (bool)(d1 == d2) << endl;
//
//	return 0;
//}




int main()
{
	Date d1(2021, 3, 1,"hello");
	Date d2(2020, 6, 9, "world");
	Date d3(d1);

	return 0;
}
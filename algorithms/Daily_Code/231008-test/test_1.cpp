#include <iostream>
#include <list>
using namespace std;
#include "List.h"


int main()
{
	bit::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	bit::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it++;
	}
	cout << endl;

	list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		cout << *rit++;
	}
	cout << endl;
	return 0;
}
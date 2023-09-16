#include <list>
#include <iostream>
using namespace std;

﻿template<typename T>

void removeduplicates(list<T>& aList)
{
	T curValue;
	list<T>::iterator cur, p;
	cur = aList.begin();

	while (cur != aList.end())
	{
		curValue = *cur;
		//空白行 1
		while (p != aList.end())
		{
			if (*p == curValue)
			{
				//空白行 2
			}
			else
			{
				p++;
			}
		}
	}
}

//int main()
//{
//	int ar[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int n = sizeof(ar) / sizeof(int);
//	list<int> mylist(ar, ar + n);
//	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);
//	reverse(mylist.begin(), pos);
//	reverse(pos, mylist.end());
//	list<int>::const_reverse_iterator crit = mylist.crbegin();
//
//	while (crit != mylist.crend())
//	{
//		cout << *crit << " ";
//		++crit;
//	}
//	cout << endl;
//
//}


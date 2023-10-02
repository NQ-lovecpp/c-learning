#include <queue>
#include <iostream>
using namespace std;
//#include "priority_queue.h"

template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

void test_priority_queue()
{
	priority_queue<int,vector<int>,greater<int>> q;
	q.push(3);
	q.push(1);
	q.push(5);
	q.push(4);

	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}

void test2()
{
	
}

int main()
{
	test_priority_queue();

	Less<int> less;
	cout << less(10,29) << endl;
	return 0;
}


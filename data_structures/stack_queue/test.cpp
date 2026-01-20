#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#include "Stack.h"
int main()
{
	bit::stack<int, vector<int>> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.pop();
	cout << s.top() << endl;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	v.resize(5, 0);
	int i = 0;
	for (int& var : v)
	{
		var = i++;
	}
 
	for (int var2 : v)
	{
		var2 = 666;
	}

	return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
struct Compare
{
	bool operator()(T left, T right)
	{
		return left > right;
	}
};

int main()
{
	int arr[10] = {5,4,7,2,8,9,1,0,2,45};
	std::sort(arr,arr+10, Compare<int>());

	for (auto e : arr)
	{
		std::cout << e << " ";
	}

	return 0;
}
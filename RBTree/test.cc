#include <iostream>
#include <vector>
using namespace std;
#include "RBTree.h"

int main()
{
	const int N = 10000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand());
		// cout << v.back() << endl;
	}

	size_t begin2 = clock();
	RBTree<int, int> t;
	for (auto e : v)
	{
		cout << t.Insert(make_pair(e, e)) << " ";
		cout << "Insert:" << e << "		Is Balanced? " << t.IsBalance() << endl;
	}
	size_t end2 = clock();

	cout << "Insert Time:" << end2 - begin2 << endl;

	cout << "t.IsBalance() = " << t.IsBalance() << endl;
	cout << "t.Height() = " << t.Height() << endl;
	cout << "t.Size() = " << t.Size() << endl;
	return 0;
}


//int main()
//{
//	int a[] = { 4,12,6,1,3,5,15,7,16,14 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//	t.InOrder();
//
//	cout << t.IsBalance() << endl;
//	return 0;
//}
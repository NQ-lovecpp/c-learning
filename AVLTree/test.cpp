//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//struct cmp
//{
//	bool operator()(int a, int b)
//	{
//		return a > b;
//	}
//};
//
//int main()
//{
//	map<string, string> dict;
//	dict.insert(make_pair("left", "×ó±ß"));
//	dict.insert(make_pair("right", "ÓÒ±ß"));
//
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//
//	//vector<int> v = { 5,8,3,4,7,2,1,6 };
//	//sort(v.begin(), v.end(), cmp());
//	//for (auto e : v)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	return 0;
//}

//#include <vector>
//#include <iostream>
//#include <utility>
//#include <cassert>
//using namespace std;
//#include "AVLTree.h"
//
//int main()
//{
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	AVLTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//	t.InOrder();
//	return 0;
//}

//int main()
//{
//	const int N = 30;
//	vector<int> v;
//	v.reserve(N);
//	//srand(time(0));
//
//	for (size_t i = 0; i < N; i++)
//	{
//		v.push_back(rand());
//		cout << v.back() << endl;
//	}
//
//	AVLTree<int, int> t;
//	for (auto e : v)
//	{
//		if (e == 14604)
//		{
//			int x = 0;
//		}
//
//		t.Insert(make_pair(e, e));
//		cout << "Insert:" << e << "->" << t.IsBalance() << endl;
//	}
//
//	cout << t.IsBalance() << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <typeinfo>
//using namespace std;
//
//template <class T1, class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 second_type;
//	T1 first;
//	T2 second;
//
//	pair()
//		:first()
//		,second()
//	{}
//
//	pair(const T1& a, const T2& b)
//		: first(a), second(b)
//	{}
//};
//
//int main()
//{
//	int i1 = 0;
//	char c1 = 'c';
//	::pair<int, char> ic;
//	cout << typeid(ic).name() << endl;
//	
//	return 0;
//}


#include <iostream>
#include <string>
#include "AVL_recite.h"
using namespace Recite;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	AVLTree<int, string> dict;

	dict.Insert(std::make_pair(5, "hello"));
	dict.Insert(std::make_pair(1, "hello"));
	dict.Insert(std::make_pair(6, "hello"));
	dict.Insert(std::make_pair(3, "hello"));
	dict.Insert(std::make_pair(2, "hello"));
	dict.Insert(std::make_pair(8, "hello"));
	dict.Insert(std::make_pair(7, "hello"));

	dict.Inorder();
	return 0;
}

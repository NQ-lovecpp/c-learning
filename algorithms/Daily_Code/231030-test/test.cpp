//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class CStudent
//{
//public:
//	CStudent(float _score = 0)
//		:score(_score)
//	{
//		total += score;
//		count++;
//	}
//
//	~CStudent()
//	{
//		count--;
//		total -= score;
//	}
//public:
//
//	float static Sum()
//	{
//		return total;
//	}
//
//	float static Average()
//	{
//		return (total / count);
//	}
//
//	static float total; //总分
//	static int count; //总人数
//private:
//	float score;
//};
//
//float CStudent::total = 0;
//int CStudent::count = 0;
//
//
//int main()
//{
//	CStudent s1(100);
//	CStudent s2(99);
//	CStudent s3(98);
//	CStudent s4(97);
//
//	CStudent arr[5] = { 96,95,94,93,92 };
//
//	cout << CStudent::Sum() << endl;
//	cout << CStudent::Average() << endl;
//
//	return 0;
//}

// AnotherFile.cpp
//#include "MyTemplate.h"
//
//int main() 
//{
//    func(42);
//    func(42.23);
//    return 0;
//}

#include <iostream>
#include <set>
#include <map>
using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(6);
	s.insert(1);

	pair<set<int>::iterator, bool>ret1 = s.insert(5);
	cout << ret1.second << endl;
	

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	s.erase(5);

	it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	std::set<int> myset;
	std::set<int>::iterator itlow, itup;

	for (int i = 1;i < 10;i++)
	{
		myset.insert(i * 10);
	}
	
	itlow = myset.lower_bound(30); //返回>=30的迭代器
	itup = myset.upper_bound(60); //返回<=60的迭代器

	myset.erase(itlow, itup);
	
	for (auto e : myset)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_set3()
{
	std::set<int> myset;

	myset.insert(10);   // myset: 10 20 30 40 50
	myset.insert(20);
	myset.insert(30);
	myset.insert(31);
	myset.insert(39);
	myset.insert(50);


	std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
	ret = myset.equal_range(31);

	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';

	for (auto e : myset)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("insert", "插入"));
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("right", "右边"));

	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << (*it).first << " " << (*it).second << endl;
		cout << it.operator->()->first << " " << (*it).second << endl;
		cout << it->first << " " << it->second << endl;

		it++;
	}

	for (auto it = dict.begin();it != dict.end();it++)
	{
		dict[it->first] = "hello world";
	}
}

int main()
{
	test_map();
	return 0;
}
//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//}
//~A()
//{
//	cout << "~A()" << endl;
//}
//private:
//	int _a;
//};
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};
//int main()
//{
//	A aa1;
//	//a aa1();
//	A();
//	A aa2(2);
//	Solution().Sum_Solution(10);
//	return 0;
//}
//#include <utility>
//#include <iostream>
//using namespace std;
//
//
//template <class T, class T1, class T2>
//T Add(T1 left, T2 right)
//{
//	return left + right;
//}
//int main()
//{
//	int x = 0, y = 1;
//	cout << x << y << endl;
//	swap(x, y);
//	cout << x << y << endl;
//
//
//	double a = 1.1, b = 2.2;
//	cout << a << b << endl;
//	swap(a, b);
//	cout << a << b << endl;
//
//	cout << Add<int, int, double>(x, a) << endl;
//
//	return 0;
//}

//
//// 动态顺序表
//// 注意：Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具
//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)
//		: _pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{
//		;
//	}
//
//	// 使用析构函数演示：在类中声明，在类外定义。
//	~Vector();
//
//	void PushBack(const T& data);
//
//	void PopBack();
//
//	size_t Size() 
//	{ 
//		return _size; 
//	}
//
//	T& operator[](size_t pos)
//	{
//		assert(pos < _size);
//		return _pData[pos];
//	}
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//
//// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
//template <class T>
//Vector<T>::~Vector()
//{
//	if (_pData)
//		delete[] _pData;
//	_size = _capacity = 0;
//}
//
//int main()
//{
//	Vector<int> v;
//	return 0;
//}
#include <string>
#include <list>
#include <iostream>
using namespace std;

void test_string1()
{
	string s1;
	string s2("hello");
	
	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;

	string ret = s1 + s2 + "我来了";
	cout << ret << endl;
}

void test_string2()
{
	string s1 = "hello world";

	for (size_t i = 0;i < s1.size();i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0;i < s1.size();i++)
	{
		s1[i]++;
	}
	cout << s1 << endl;

	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = s1.begin();
	while (it != s1.end())
	{
		*it = 'a';
		++it;
	}

	cout << s1 << endl;

}

void testlist()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	//迭代器
	list<int>::iterator lit = lt.begin();

	while (lit != lt.end())
	{
		cout << *lit << endl;
		lit++;
	}
	cout << endl;
}

void test_string3()
{
	string s1("hello world");
	//string::reverse_iterator rit = s1.rbegin();

	auto rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	//范围for
	for (auto ch : s1)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;
	
}

void func(const string& s)
{
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_string4()
{
	string s1("hello world");
	func(s1);

	string s2(s1);
	cout << s2 << endl;

	string s3(s1, 6, 5);
	cout << s3 << endl;

	string s4(s1, 6, 3);
	cout << s4 << endl;

	string s5(s1, 6, s1.size() - 6);
	cout << s5 << endl;

	string s7(10, 'a');
	cout << s7 << endl;

	string s8(++s1.begin(), --s1.end());
	cout << s8 << endl;

	s8 = s7;
	s8 = "xxx";
	s8 = 'y';

}

void test_string5()
{
	string s1 = "hello world";
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;

	cout << "---" << endl;
	s1.clear();
	s1 += "张三";
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << s1.max_size() << endl;
}


//int main()
//{
//	//test_string4();
//	//testlist();
//	//test_string5();
//	
//	return 0;
//}
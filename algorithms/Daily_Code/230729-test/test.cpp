//#include <iostream>
//using namespace std;

//class A
//{
//public:
//	A() 
//	{ 
//		++_scount;
//	}
//	A(const A& t) 
//	{ 
//		++_scount; 
//	}
//	~A() 
//	{ 
//		--_scount; 
//	}
//	static int GetACount() 
//	{ 
//		return _scount; 
//	}
////private:
//	static int _scount;
//};
//int A::_scount = 0;
//
//
//void TestA()
//{
//	A a1;
//	cout << a1._scount << endl;
//
//	cout << A::_scount << endl;
//
//	cout << A()._scount << endl;
//
//	A* ptra = nullptr;
//	cout << ptra->_scount << endl;
//
//	cout << "---------------" << endl;
//
//	cout << A::GetACount() << endl;
//	A aa1, aa2;
//	A aa3(aa1);
//	cout << A::GetACount() << endl;
//}
//
//int main()
//{
//	TestA();
//	return 0;
//}

//class A
//{
//public:
//	class B
//	{
//	private:
//		int _b;
//	};
//private:
//	int _a;
//};
//
//
//int main()
//{
//	A a;
//	A::B b;
//	cout << sizeof(A) << endl;
//	cout << sizeof(a) << endl;
//	cout << sizeof(A::B) << endl;
//	cout << sizeof(b) << endl;
//	return 0;
//}

//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
//class A
//{
//
//};
//
//struct ListNode
//{
//	ListNode* _next;
//	int _val;
//
//	ListNode(int val = 0)
//		:_val(0)
//		:
//	{
//
//	}
//};
//int main()
//{
//	int* p2 = (int*)malloc(sizeof(int));
//	free(p2);
//
//	int* p3 = new int;
//	delete p3;
//
//	int* a = new int[10];
//	delete[] a;
//
//	int* p6 = new int(1);//初始化成1
//	delete p6;
//	int* p7 = new int[10] {1,2,3,4,5,6};//数组初始化
//	delete[] p7;
//
//	A* p8 = new A;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	static void test1()
//	{
//		cout << "static void test1()" << endl;
//		StaticVar = 456;
//	}
//
//	void test2()
//	{
//		test1();
//	}
//	static int StaticVar;
//};
//int A::StaticVar = 123;
//
//int main()
//{
//	A a1;
//	cout << a1.StaticVar << endl;
//	a1.test2();
//	cout << a1.StaticVar << endl;
//	return 0;
//}

#include <iostream>
using namespace std;


class T
{
public:
	static int f2()
	{
		this;
	}

protected:
	int f4()
	{
		this;
	}

};
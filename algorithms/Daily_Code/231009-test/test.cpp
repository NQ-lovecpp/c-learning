//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int num = 0;
//    cin >> num;
//
//    vector<int> arr;
//    arr.resize(1000,0);
//    arr[0] = 0;
//    arr[1] = 1;
//    arr[2] = 1;
//    int i = 2;
//    for (i = 2;arr[i-1] < num;i++)
//    {
//        arr[i] = arr[i - 1] + arr[i - 2];  
//    }
//    cout << arr[i - 1] << endl;
//    int s1 = num - arr[i - 1];
//    int s2 = arr[i] - num;
//
//    int out = s1 > s2 ? s1 : s2;
//    cout << out;
//}
//
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	for (int i = 0;i < 10;i++)
//	{
//		cout << i << " ";
//	}
////}
//
//#include <iostream>
//using namespace std;
//template<typename Type>
//Type Max(const Type& a, const Type& b)
//{
//	cout << "This is Max<Type>" << endl;
//	return a > b ? a : b;
//}
//
//template<>
//int Max<int>(const int& a, const int& b)
//{
//	cout << "This is Max<int>" << endl;
//	return a > b ? a : b;
//}
//
//template<>
//char Max<char>(const char& a, const char& b)
//{
//	cout << "This is Max<char>" << endl;
//	return a > b ? a : b;
//}
//
//int Max(const int& a, const int& b)
//{
//	cout << "This is Max" << endl;
//	return a > b ? a : b;
//}
//
//int main()
//{
//	Max(10, 20);
//	Max(12.34, 23.45);
//	Max('A', 'B');
//	Max<int>(20, 30);
//	return 0;
//}

#include <iostream>
using namespace std;
template<class T1, class T2>
class Data
{
public:
	Data() 
	{ 
		cout << "Data<T1, T2>" << endl; 
	}
private:
	T1 _d1;
	T2 _d2;
};

template <class T1>
class Data<T1, int>
{
public:
	Data() 
	{
		cout << "Data<T1, int>" << endl; 
	}
private:
	T1 _d1;
	int _d2;
};

template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data()
	{ 
		cout << "Data<T1*, T2*>" << endl; 
	}
private:
	T1 _d1;
	T2 _d2;
};

template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};

int main()
{
	Data<double, int> d1;
	Data<int, double> d2;
	Data<int*, int*> d3;
	Data<int&, int&> d4(1, 2);
	return 0;
}
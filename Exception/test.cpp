//#include <stdio.h>
//#include <assert.h>
//
//void divide(int a, int b) 
//{
//    assert(b != 0);  // 防止除0错误：如果b为0，则终止程序
//    int result = a / b;
//    printf("Result: %d\n", result);
//}
//
//int main() 
//{
//    divide(10, 2);    // 正常情况
//    divide(5, 0);     // 会终止程序，因为除数为0
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int divide(int a, int b, int* result) 
//{
//    if (b == 0) 
//    {
//        return -1;  // 返回错误码表示除数为0
//    }
//    *result = a / b;
//    return 0;       // 返回0表示成功
//}
//
//int main() 
//{
//    int result;
//    int status;
//
//    status = divide(10, 2, &result);
//    if (status == 0) 
//    {
//        printf("Result: %d\n", result);
//    }
//    else 
//    {
//        printf("Error: Division by zero\n");
//    }
//
//    status = divide(5, 0, &result);
//    if (status == 0) 
//    {
//        printf("Result: %d\n", result);
//    }
//    else 
//    {
//        printf("Error: Division by zero\n");
//    }
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//
//int main() {
//    FILE* file = fopen("nonexistent_file.txt", "r");
//
//    if (file == NULL) {
//        // 函数调用失败，检查 errno 获取错误信息
//        perror("Error opening file");
//        fprintf(stderr, "errno = %d\n", errno);
//
//        // 根据错误码进行处理
//        if (errno == ENOENT) {
//            fprintf(stderr, "File not found\n");
//        }
//        else if (errno == EACCES) {
//            fprintf(stderr, "Permission denied\n");
//        }
//        else {
//            fprintf(stderr, "Unknown error\n");
//        }
//
//        exit(EXIT_FAILURE);
//    }
//
//    // 在实际的程序中，这里会进行文件读取等操作
//
//    fclose(file);
//    return 0;
//}

#define _CRT_SECURE_NO_WARNINGS


//#include <stdio.h>
//#include <math.h>
//#include <errno.h>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	double ret = asin(10);
//	fprintf(stderr, "errno = %d\n", errno);
//	cerr << errno <<" "<< strerror(errno) << endl;
//	//perror("asin error");
//	vector<int> vec;
//	vec[0];
//	return 0;
//}



//#include <stdio.h>
//#include <math.h>
//#include <errno.h>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//double Division(int len, int time)
//{
//	if (time == 0)
//	{
//		throw "除0错误";
//	}
//	else
//	{
//		return (double)len / (double)time;
//	}
//}
//
//void Func()
//{
//	A aa;
//
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char* s)
//	{
//		cout << s << endl;
//	}
//
//	//cout << "xxxxxxxxxxxx" << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//
//	return 0;
//}

//
//#include <stdio.h>
//#include <math.h>
//#include <errno.h>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//void func3()
//{
//	A a3;
//	try
//	{
//		// ...
//		throw("I am an exception!");
//	}
//	catch (char ch)
//	{
//		cout << ch << endl;
//	}
//}
//
//void func2()
//{
//	A a2;
//	try
//	{
//		func3();
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//}
//
//void func1()
//{
//	A a1;
//	try
//	{
//		func2();
//	}
//	catch (int intagernum)
//	{
//		cout << intagernum << endl;
//	}
//}
//
//int main()
//{
//	try
//	{
//		func1();
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//	return 0;
//}

//#include <string>
//#include <iostream>
//using namespace std;
//
//void func1()
//{
//	throw string("这是一个异常");
//}
//void func2()
//{
//	int* array = new int[10];
//	try
//	{
//		func1();
//		//do something...
//	}
//	catch (...)
//	{
//		delete[] array;
//		throw; //将捕获到的异常再次重新抛出
//	}
//	delete[] array;
//}
//int main()
//{
//	try
//	{
//		func2();
//	}
//	catch (const string& s)
//	{
//		cout << s << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//	return 0;
//}


//#include <string>
//#include <iostream>
//#include <vector>
//#include <errno.h>
//using namespace std;
//
//int main()
//{
//	try 
//	{
//		vector<int> v(10, 5);
//		// 这里如果系统内存不够也会抛异常
//		v.reserve(1000000000000000);
//		// 这里越界会抛异常
//		v.at(10) = 100;
//	}
//	catch (const exception& e) // 这里捕获父类对象就可以
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}
//	return 0;
//}


//// 这里表示这个函数会抛出A/B/C/D中的某种类型的异常
//void fun() throw(A，B，C，D);
//// 这里表示这个函数只会抛出bad_alloc的异常
//void* operator new (std::size_t size) throw (std::bad_alloc);
//// 这里表示这个函数不会抛出异常
//void* operator delete (std::size_t size, void* ptr) throw();
//// C++11 中新增的noexcept，表示不会抛异常
//thread() noexcept;
//thread(thread&& x) noexcept;



//#include <iostream>
//#include <string>
//#include <Windows.h>
//
//using namespace std;
//
//
//// 服务器开发中通常使用的异常继承体系
//class Exception
//{
//public:
//	Exception(const string& errmsg, int id)
//		:_errmsg(errmsg)
//		, _id(id)
//	{}
//	virtual string what() const
//	{
//		return _errmsg;
//	}
//protected:
//	string _errmsg; // 错误描述
//	int _id;        // 错误编号
//};
//
//class SqlException : public Exception
//{
//public:
//	SqlException(const string& errmsg, int id, const string& sql)
//		:Exception(errmsg, id)
//		, _sql(sql)
//	{}
//	virtual string what() const
//	{
//		string str = "SqlException:";
//		str += _errmsg;
//		str += "->";
//		str += _sql;
//		return str;
//	}
//private:
//	const string _sql;
//};
//
//class CacheException : public Exception
//{
//public:
//	CacheException(const string& errmsg, int id)
//		:Exception(errmsg, id)
//	{}
//	virtual string what() const override
//	{
//		string str = "CacheException:";
//		str += _errmsg;
//		return str;
//	}
//};
//
//class HttpServerException : public Exception
//{
//public:
//	HttpServerException(const string& errmsg, int id, const string& type)
//		:Exception(errmsg, id)
//		, _type(type)
//	{}
//	virtual string what() const
//	{
//		string str = "HttpServerException:";
//		str += _type;
//		str += ":";
//		str += _errmsg;
//		return str;
//	}
//private:
//	const string _type;
//};
//
//void SQLMgr()
//{
//	srand(time(0));
//	if (rand() % 7 == 0)
//	{
//		throw SqlException("权限不足", 100, "select * from name = '张三'");
//	}
//}
//
//void CacheMgr()
//{
//	srand(time(0));
//	if (rand() % 5 == 0)
//	{
//		throw CacheException("权限不足", 100);
//	}
//	else if (rand() % 6 == 0)
//	{
//		throw CacheException("数据不存在", 101);
//	}
//	SQLMgr();
//}
//
//void HttpServer()
//{
//	// ...
//	srand(time(0));
//	if (rand() % 3 == 0)
//	{
//		throw HttpServerException("请求资源不存在", 100, "get");
//	}
//	else if (rand() % 4 == 0)
//	{
//		throw HttpServerException("权限不足", 101, "post");
//	}
//	CacheMgr();
//}
//
//int main()
//{
//	while (1)
//	{
//		Sleep(500);
//		try {
//			HttpServer();
//		}
//		catch (const Exception& e) // 这里捕获父类对象就可以
//		{
//			// 多态
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//	return 0;
//}

#include <vector>
#include <iostream>
using namespace std;


//
//int main()
//{
//	try 
//	{
//		vector<int> v(10, 5);
//
//		// 这里如果系统内存不够会抛异常
//		v.reserve(100000000000);
//
//		// 这里越界会抛异常
//		v.at(10) = 100;
//	}
//	catch (const exception& e) // 这里捕获父类对象就可以
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}
//	return 0;
//}


double Division(int a, int b) noexcept
{
	// 当b == 0时抛出异常
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}
void Func()
{
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}
int main()
{
	try {
		Func();
	}
	catch (const char* errmsg )
	{
		cout << errmsg << endl;
	}
	catch (...) 
	{
		cout << "unkown exception" << endl;
	}
	return 0;
}

